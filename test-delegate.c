#include <stdio.h>
#include <delegate.h>

void func1(void* p)
{
    puts(__func__);
}

void func2(void* p)
{
    puts(__func__);
}
void func3(void* p)
{
    puts(__func__);
}
void func4(void* p)
{
    puts(__func__);
}

int main()
{
    delegate_init();

    struct delegate d = {.begin = NULL};

    delegate_add(&d, func1);
    delegate_add(&d, func2);
    delegate_invoke(&d);

    delegate_add(&d, func3);
    delegate_add(&d, func4);

    delegate_invoke(&d);

    delegate_remove(&d, func3);
    delegate_invoke(&d);

    return 0;
}