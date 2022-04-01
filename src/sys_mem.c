#include <sys_mem.h>
#include <sys_mem_internal.h>
#include <util.h>

#define ALIGNED_MASK (sizeof(void *) - 1)

struct sys_mem *sys_mem_create(struct sys_mem *pmem, void *addr, uint32_t size, uint32_t blksize)
{
    void **pblk;
    void **plink;
    int32_t i;
    uint32_t nblks;

    void **addr_aligned;
    uint32_t blksize_aligned;
    uint32_t __blksize; /* = block size / sizeof(void*) */

    if ((size < blksize) || !pmem || !addr)
    {
        return ((struct sys_mem *)0);
    }

    addr_aligned = (void **)ROUND_UP(addr, sizeof(void *));
    blksize_aligned = (uint32_t)ROUND_UP(blksize, sizeof(void *));
    __blksize = blksize_aligned / sizeof(void *);

    nblks = (size - ((sizeof(void *) - ((uintptr_t)addr & ALIGNED_MASK)) & ALIGNED_MASK)) / blksize_aligned;

    plink = (void **)addr_aligned; /* Create linked list of free memory blocks      */
    pblk = addr_aligned + __blksize;

    for (i = 0; i < (nblks - 1); i++)
    {
        *plink = (void *)pblk; /* Save pointer to NEXT block in CURRENT block   */
        plink = pblk;          /* Position to  NEXT      block                  */
        pblk += __blksize;     /* Point to the FOLLOWING block                  */
    }

    *plink = (void *)0;                 /* Last memory block points to NULL              */
    pmem->mem_free_list = addr_aligned; /* Initialize pointer to pool of free blocks     */
    pmem->numFreeBlks = nblks;          /* Store number of free blocks in MCB            */
    pmem->numBlks = nblks;
    pmem->blkSize = blksize_aligned; /* Store block size of each memory blocks        */

    return (pmem);
}

void *sys_mem_get(struct sys_mem *pmem)
{
    void *pblk;

    OS_CPU_SR_DEFINE;

    OS_ENTER_CRITICAL();
    if (pmem->numFreeBlks > 0)
    {                                         /* See if there are any free memory blocks       */
        pblk = pmem->mem_free_list;           /* Yes, point to next free memory block          */
        pmem->mem_free_list = *(void **)pblk; /*      Adjust pointer to new free list          */
        pmem->numFreeBlks--;                  /*      One less memory block in this partition  */
        OS_EXIT_CRITICAL();

        return (pblk); /*      Return memory block to caller            */
    }
    OS_EXIT_CRITICAL();

    return ((void *)0); /*      Return NULL pointer to caller            */
}

int8_t sys_mem_put(struct sys_mem *pmem, void *pblk)
{
    OS_CPU_SR_DEFINE;

    OS_ENTER_CRITICAL();
    if (pmem->numFreeBlks >= pmem->numBlks)
    { /* Make sure all blocks not already returned          */
        OS_EXIT_CRITICAL();
        return -1;
    }
    *(void **)pblk = pmem->mem_free_list; /* Insert released block into free block list         */
    pmem->mem_free_list = pblk;
    pmem->numFreeBlks++; /* One more memory block in this partition            */
    OS_EXIT_CRITICAL();

    return 0; /* Notify caller that memory block was released       */
}
