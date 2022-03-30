#ifndef __STIMER__H__
#define __STIMER__H__

#include <linklist.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct sTimer
{
    struct slist_node __node;
    unsigned int period;
    unsigned int __nextAlarm;
    bool flag;
};

void sTimer_tick(void);
void sTimer_start(struct sTimer *pTimer);
void sTimer_stop(struct sTimer *pTimer);

#ifdef __cplusplus
}
#endif

#endif