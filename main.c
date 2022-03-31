#include <stdio.h>
#include <os_mem.h>

uint64_t stack[2];

int main ()
{
    int8_t perr;
    void * a1, *a2;

    OS_MEM *pmem = OSMemCreate(&stack, 2, 8, &perr);
    
    printf("err: %d\n", perr);

    a1 = OSMemGet(pmem, &perr);
    printf("err: %d\n", perr);

    a2 = OSMemGet(pmem, &perr);
    printf("err: %d\n", perr);

    OSMemPut(pmem, a1);
    a1 = OSMemGet(pmem, &perr);
    printf("err: %d\n", perr);

    a2 = OSMemGet(pmem, &perr);
    printf("err: %d\n", perr);

    a1 = OSMemGet(pmem, &perr);
    printf("err: %d\n", perr);

    return 0;
}