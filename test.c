#include <linklist.h>
#include <stddef.h>
#include <stdio.h>

struct test_list
{
    struct slist_node node;
    int x;
};

static int eval(const struct slist_node *node)
{
    return CONTAINER_OF(node, struct test_list, node)->x;
}

static void(slist_print)(const struct slist_node *_node)
{
    printf("%d\n", eval(_node));
}

int main()
{
    struct test_list x1 = {{NULL}, 7};
    struct test_list x2 = {{&x1.node}, 4};
    struct test_list x3 = {{&x2.node}, -2};
    struct test_list x4 = {{&x3.node}, 8};
    struct test_list x5 = {{&x4.node}, 1};

    struct slist_node *begin = &x5.node;

    slist_sort(&begin, eval, false);

    slist_foreach(&begin, slist_print);

    slist_sort(&begin, eval, true);
    puts("");

    slist_foreach(&begin, slist_print);

    return 0;
}
