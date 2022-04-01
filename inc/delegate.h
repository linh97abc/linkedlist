#ifndef __DELEGATE_H__
#define __DELEGATE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

struct delegate
{
    struct slist_node *begin;
    const char *name;
    void *arg;
};

int delegate_init(void);
void delegate_invoke(const struct delegate *_delegate);
bool delegate_add(struct delegate *_delegate, void (*cb)(void*));
bool delegate_remove(struct delegate *_delegate, void (*cb)(void*));

#ifdef __cplusplus
}
#endif
#endif
