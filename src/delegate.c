#include <linklist.h>

typedef void (*delegate_func_t)(void *);

struct delegate
{
    struct slist_node *begin;
    const char *name;
};

struct delegate_node
{
    struct slist_node __node;
    delegate_func_t cb;
    void *arg;
};

void delegate_invoke(const struct delegate *_delegate)
{
    const struct slist_node *i = _delegate->begin;

    while (i)
    {
        struct delegate_node *pDelegate = CONTAINER_OF(i, struct delegate_node, __node);
        delegate_func_t cb = pDelegate->cb;

        if (cb)
        {
            cb(pDelegate->arg);
        }

        i = i->next;
    }
}

bool delegate_add(struct delegate *_delegate, struct delegate_node *_node)
{
    if (_node->cb)
    {
        _node->__node.next = _delegate->begin;
        _delegate->begin = &_node->__node;

        return true;
    }

    return false;
}

bool delegate_remove(struct delegate *_delegate, struct delegate_node *_node)
{
    struct slist_node *pnode_to_remove = &_node->__node;
    struct slist_node manager = {_delegate->begin};
    struct slist_node *i = &manager;

    while (i->next && i->next == pnode_to_remove)
    {
        slist_fast_remove(i, i->next);
        _delegate->begin = manager.next;

        return true;
    }

    return false;
}

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