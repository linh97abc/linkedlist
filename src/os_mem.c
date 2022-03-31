#ifndef __ucosii__

#include <os_mem.h>
#include <os_mem_internal.h>

#define UTIL_PRIMITIVE_CAT(a, ...) a##__VA_ARGS__
#define UTIL_CAT(a, ...) UTIL_PRIMITIVE_CAT(a, __VA_ARGS__)

#define OSMemTb_Begin UTIL_CAT(OSMemTbl, OS_MAX_MEM_PART)

static OS_MEM OSMemTbl1 = {.OSMemFreeList = (void *)0};
#if OS_MAX_MEM_PART > 1
static OS_MEM OSMemTbl2 = {.OSMemFreeList = &OSMemTbl1};
#endif
#if OS_MAX_MEM_PART > 2
static OS_MEM OSMemTbl3 = {.OSMemFreeList = &OSMemTbl2};
#endif
#if OS_MAX_MEM_PART > 3
static OS_MEM OSMemTbl4 = {.OSMemFreeList = &OSMemTbl3};
#endif

static OS_MEM *OSMemFreeList = &OSMemTb_Begin;

static void OS_MemClr(int8_t *pdest, int16_t size)
{
    while (size > 0u)
    {
        *pdest++ = (int8_t)0;
        size--;
    }
}

#define SET_PERR(perr, val) \
    do                      \
    {                       \
        if (perr)           \
        {                   \
            *perr = val;    \
        }                   \
    } while (0)

OS_MEM *OSMemCreate(void *addr, int32_t nblks, int32_t blksize, int8_t *perr)
{
    OS_MEM *pmem;
    int8_t *pblk;
    void **plink;
    int32_t i;

    OS_CPU_SR_DEFINE;

    if (((uintptr_t)addr & (sizeof(void *) - 1)) != 0){  /* Must be pointer size aligned                  */
        SET_PERR(perr, OS_ERR_MEM_INVALID_ADDR);
        return ((OS_MEM *)0);
    }
    if (nblks < 2) {                                  /* Must have at least 2 blocks per partition     */
        SET_PERR(perr, OS_ERR_MEM_INVALID_BLKS);
        return ((OS_MEM *)0);
    }
    if (blksize < sizeof(void *)) {                   /* Must contain space for at least a pointer     */
        SET_PERR(perr, OS_ERR_MEM_INVALID_SIZE);
        return ((OS_MEM *)0);
    }

    OS_ENTER_CRITICAL();
    pmem = OSMemFreeList; /* Get next free memory partition                */
    if (OSMemFreeList)
    { /* See if pool of free partitions was empty      */
        OSMemFreeList = (OS_MEM *)OSMemFreeList->OSMemFreeList;
    }
    OS_EXIT_CRITICAL();
    if (!pmem)
    { /* See if we have a memory partition             */
        SET_PERR(perr, OS_ERR_MEM_INVALID_PART);
        return ((OS_MEM *)0);
    }
    plink = (void **)addr; /* Create linked list of free memory blocks      */
    pblk = (int8_t *)((uintptr_t)addr + blksize);
    for (i = 0; i < (nblks - 1); i++)
    {
        *plink = (void *)pblk;                      /* Save pointer to NEXT block in CURRENT block   */
        plink = (void **)pblk;                      /* Position to  NEXT      block                  */
        pblk = (int8_t *)((uintptr_t)pblk + blksize); /* Point to the FOLLOWING block                  */
    }
    *plink = (void *)0;         /* Last memory block points to NULL              */
    pmem->OSMemAddr = addr;     /* Store start address of memory partition       */
    pmem->OSMemFreeList = addr; /* Initialize pointer to pool of free blocks     */
    pmem->OSMemNFree = nblks;   /* Store number of free blocks in MCB            */
    pmem->OSMemNBlks = nblks;
    pmem->OSMemBlkSize = blksize; /* Store block size of each memory blocks        */
    SET_PERR(perr, OS_ERR_NONE);
    return (pmem);
}

void *OSMemGet(OS_MEM *pmem, int8_t *perr)
{
    void *pblk;

    OS_CPU_SR_DEFINE;

    OS_ENTER_CRITICAL();
    if (pmem->OSMemNFree > 0)
    {                                         /* See if there are any free memory blocks       */
        pblk = pmem->OSMemFreeList;           /* Yes, point to next free memory block          */
        pmem->OSMemFreeList = *(void **)pblk; /*      Adjust pointer to new free list          */
        pmem->OSMemNFree--;                   /*      One less memory block in this partition  */
        OS_EXIT_CRITICAL();
        SET_PERR(perr, OS_ERR_NONE); /*      No error                                 */

        return (pblk); /*      Return memory block to caller            */
    }
    OS_EXIT_CRITICAL();
    SET_PERR(perr, OS_ERR_MEM_NO_FREE_BLKS); /* No,  Notify caller of empty memory partition  */
    return ((void *)0);                      /*      Return NULL pointer to caller            */
}

int8_t OSMemPut(OS_MEM *pmem, void *pblk)
{
    OS_CPU_SR_DEFINE;

    OS_ENTER_CRITICAL();
    if (pmem->OSMemNFree >= pmem->OSMemNBlks)
    { /* Make sure all blocks not already returned          */
        OS_EXIT_CRITICAL();
        return (OS_ERR_MEM_FULL);
    }
    *(void **)pblk = pmem->OSMemFreeList; /* Insert released block into free block list         */
    pmem->OSMemFreeList = pblk;
    pmem->OSMemNFree++; /* One more memory block in this partition            */
    OS_EXIT_CRITICAL();
    return (OS_ERR_NONE); /* Notify caller that memory block was released       */
}

#endif
