#include <linklist.h>
#include <sys_mem.h>
#include <delegate.h>

#define MAX_DELEGATE_NODE 128

struct delegate_node
{
    struct slist_node __node;
    delegate_func_t cb;
};

static struct sys_mem memDelegate;
static struct delegate_node g_node[MAX_DELEGATE_NODE];

int delegate_init(void)
{
    struct sys_mem *pmem;

    pmem = sys_mem_create(&memDelegate, g_node, sizeof(g_node), sizeof(struct delegate_node));

    return (pmem != (void*)0);
}

void delegate_invoke(const struct delegate *_delegate)
{
    const struct slist_node *i = _delegate->begin;

    while (i)
    {
        struct delegate_node *pDelegate = CONTAINER_OF(i, struct delegate_node, __node);
        delegate_func_t cb = pDelegate->cb;

        if (cb)
        {
            cb(_delegate->arg);
        }

        i = i->next;
    }
}

bool delegate_add(struct delegate *_delegate, delegate_func_t cb)
{
    if (cb)
    {
        struct delegate_node *node = (struct delegate_node *)sys_mem_get(&memDelegate);

        if (!node)
        {
            return false;
        }

        node->__node.next = _delegate->begin;
        node->cb = cb;
        _delegate->begin = &node->__node;

        return true;
    }

    return false;
}

bool delegate_remove(struct delegate *_delegate, delegate_func_t cb)
{
    struct slist_node manager = {_delegate->begin};
    struct slist_node *i = &manager;
    struct delegate_node *pnode = CONTAINER_OF(i->next, struct delegate_node, __node);

    while (i->next)
    {
        if (pnode->cb == cb)
        {
            slist_fast_remove(i, i->next);
            _delegate->begin = manager.next;
            sys_mem_put(&memDelegate, pnode);

            return true;
        }

        i = i->next;
        pnode = CONTAINER_OF(i->next, struct delegate_node, __node);
    }

    return false;
}

#if 0
extern struct delegate g_delegate[];
extern unsigned int g_size;

static bool subcrise_find_and_do(const char *s,
                                 struct delegate_node *_node,
                                 bool (*_cb)(struct delegate *, struct delegate_node *))
{
    int i;

    for (i = 0; i < g_size; i++)
    {
        if (g_delegate[i].name == s)
        {
            return _cb(&g_delegate[i], _node);
        }
    }

    return false;
}

bool subcrise_add(const char *s, struct delegate_node *_node)
{
    return subcrise_find_and_do(s, _node, delegate_add);
}

bool subcrise_remove(const char *s, struct delegate_node *_node)
{
    return subcrise_find_and_do(s, _node, delegate_remove);
}

#endif
