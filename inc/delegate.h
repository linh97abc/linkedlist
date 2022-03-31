#ifndef __DELEGATE_H__
#define __DELEGATE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef void (*delegate_func_t)(void *);

struct delegate
{
    struct slist_node *begin;
    const char *name;
    void *arg;
};

int delegate_init(void);
void delegate_invoke(const struct delegate *_delegate);
bool delegate_add(struct delegate *_delegate, delegate_func_t cb);
bool delegate_remove(struct delegate *_delegate, delegate_func_t cb);

#ifdef __cplusplus
}
#endif
#endif
