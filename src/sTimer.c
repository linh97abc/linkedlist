#include <linklist.h>
#include <stdbool.h>
#include <sTimer.h>

static struct slist_node sTimer_node;
static unsigned int tick;

static int getNextAlarm(const struct slist_node *pnode)
{
    struct sTimer *pTimer = CONTAINER_OF(pnode, struct sTimer, __node);
    int tickint = (int)tick;

    return (int)(pTimer->__nextAlarm) - tickint;
}

void sTimer_tick(void)
{
    struct slist_node *i, *i_pre;
    int tickint = (int)tick;

    i = sTimer_node.next;
    i_pre = &sTimer_node;

    while (i != NULL)
    {
        struct sTimer *pTimer = CONTAINER_OF(i, struct sTimer, __node);

        if (tickint - (int)(pTimer->__nextAlarm) >= 0)
        {
            pTimer->flag = true;
            pTimer->__nextAlarm += pTimer->period;
        }
        else
        {
            break;
        }

        i_pre = i;
        i = i->next;
    }

    if (i_pre != &sTimer_node)
    {
        struct slist_node listTimerAlarm = {sTimer_node.next};

        sTimer_node.next = i;
        i_pre->next = NULL;

        /**
         * FIXME: nên sắp xếp list timer trước khi add hay ko? 
         * */
        slist_sort(&listTimerAlarm.next, getNextAlarm, false);

        while (i != NULL)
        {
            if (i->next == NULL)
            {
                i->next = listTimerAlarm.next;
                break;
            }
            else if (getNextAlarm(i->next) > getNextAlarm(listTimerAlarm.next))
            {
                struct slist_node *currentTimerAlarm = listTimerAlarm.next;
                struct slist_node *i_next = i->next;

                listTimerAlarm.next = listTimerAlarm.next->next;
                slist_fast_add(i, currentTimerAlarm);
                i = i_next;
            }
        }
    }

    tick++;
}

void sTimer_start(struct sTimer *pTimer)
{
    struct slist_node *i;
    struct slist_node *pnode_to_add = &pTimer->__node;
    int alarm_of_addtimer;

    pTimer->__nextAlarm = tick + pTimer->period;
    pTimer->flag = false;

    alarm_of_addtimer = pTimer->period;

    i = sTimer_node.next;

    if (getNextAlarm(i) > alarm_of_addtimer)
    {
        pnode_to_add->next = i;
        sTimer_node.next = pnode_to_add;
    }
    else
    {
        while (i != NULL)
        {
            if (i->next == NULL)
            {
                i->next = pnode_to_add;
                pnode_to_add->next = NULL;
                break;
            }
            else if (getNextAlarm(i->next) > alarm_of_addtimer)
            {
                pnode_to_add->next = i->next;
                i->next = pnode_to_add;
                break;
            }
        }
    }
}

void sTimer_stop(struct sTimer *pTimer)
{
    slist_remove(&sTimer_node.next, pTimer);
}