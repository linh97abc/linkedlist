#include <stdio.h>
#include <sys_mem.h>

uint64_t stack[2];

int main ()
{
    int8_t perr;
    void * a1, *a2;

    struct sys_mem mem;
    
    sys_mem_create(&mem, &stack, sizeof(stack), 8);
    
    // printf("err: %d\n", perr);

    a1 = sys_mem_get(&mem);
    printf("err: %x\n", a1);

    a2 = sys_mem_get(&mem);
    printf("err: %x\n", a2);

    sys_mem_put(&mem, a1);
    a1 = sys_mem_get(&mem);
    printf("err: %x\n", a1);

    a2 = sys_mem_get(&mem);
    printf("err: %x\n", a2);

    a1 = sys_mem_get(&mem);
    printf("err: %x\n", a1);

    return 0;
}