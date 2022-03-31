#if !defined(__ucosii__) && !defined(__OS_MEM_H_)
#define __OS_MEM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OS_ERR_NONE                   0u
#define OS_ERR_MEM_INVALID_PART      90u
#define OS_ERR_MEM_INVALID_BLKS      91u
#define OS_ERR_MEM_INVALID_SIZE      92u
#define OS_ERR_MEM_NO_FREE_BLKS      93u
#define OS_ERR_MEM_FULL              94u
#define OS_ERR_MEM_INVALID_PBLK      95u
#define OS_ERR_MEM_INVALID_PMEM      96u
#define OS_ERR_MEM_INVALID_PDATA     97u
#define OS_ERR_MEM_INVALID_ADDR      98u
#define OS_ERR_MEM_NAME_TOO_LONG     99u

typedef struct os_mem {                   /* MEMORY CONTROL BLOCK                                      */
    void   *OSMemAddr;                    /* Pointer to beginning of memory partition                  */
    void   *OSMemFreeList;                /* Pointer to list of free memory blocks                     */
    int32_t  OSMemBlkSize;                 /* Size (in bytes) of each block of memory                   */
    int32_t  OSMemNBlks;                   /* Total number of blocks in this partition                  */
    int32_t  OSMemNFree;                   /* Number of memory blocks remaining in this partition       */
} OS_MEM;


/*
*********************************************************************************************************
*                                        CREATE A MEMORY PARTITION
*
* Description : Create a fixed-sized memory partition that will be managed by uC/OS-II.
*
* Arguments   : addr     is the starting address of the memory partition
*
*               nblks    is the number of memory blocks to create from the partition.
*
*               blksize  is the size (in bytes) of each block in the memory partition.
*
*               perr     is a pointer to a variable containing an error message which will be set by
*                        this function to either:
*
*                        OS_ERR_NONE              if the memory partition has been created correctly.
*                        OS_ERR_MEM_INVALID_ADDR  if you are specifying an invalid address for the memory
*                                                 storage of the partition or, the block does not align
*                                                 on a pointer boundary
*                        OS_ERR_MEM_INVALID_PART  no free partitions available
*                        OS_ERR_MEM_INVALID_BLKS  user specified an invalid number of blocks (must be >= 2)
*                        OS_ERR_MEM_INVALID_SIZE  user specified an invalid block size
*                                                   - must be greater than the size of a pointer
*                                                   - must be able to hold an integral number of pointers
* Returns    : != (OS_MEM *)0  is the partition was created
*              == (OS_MEM *)0  if the partition was not created because of invalid arguments or, no
*                              free partition is available.
*********************************************************************************************************
*/

OS_MEM *OSMemCreate(void *addr, int32_t nblks, int32_t blksize, int8_t *perr);

/*
*********************************************************************************************************
*                                          GET A MEMORY BLOCK
*
* Description : Get a memory block from a partition
*
* Arguments   : pmem    is a pointer to the memory partition control block
*
*               perr    is a pointer to a variable containing an error message which will be set by this
*                       function to either:
*
*                       OS_ERR_NONE             if the memory partition has been created correctly.
*                       OS_ERR_MEM_NO_FREE_BLKS if there are no more free memory blocks to allocate to caller
*                       OS_ERR_MEM_INVALID_PMEM if you passed a NULL pointer for 'pmem'
*
* Returns     : A pointer to a memory block if no error is detected
*               A pointer to NULL if an error is detected
*********************************************************************************************************
*/

void *OSMemGet(OS_MEM *pmem, int8_t *perr);

/*
*********************************************************************************************************
*                                         RELEASE A MEMORY BLOCK
*
* Description : Returns a memory block to a partition
*
* Arguments   : pmem    is a pointer to the memory partition control block
*
*               pblk    is a pointer to the memory block being released.
*
* Returns     : OS_ERR_NONE              if the memory block was inserted into the partition
*               OS_ERR_MEM_FULL          if you are returning a memory block to an already FULL memory
*                                        partition (You freed more blocks than you allocated!)
*               OS_ERR_MEM_INVALID_PMEM  if you passed a NULL pointer for 'pmem'
*               OS_ERR_MEM_INVALID_PBLK  if you passed a NULL pointer for the block to release.
*********************************************************************************************************
*/

int8_t OSMemPut(OS_MEM *pmem, void *pblk);

#ifdef __cplusplus
}
#endif

#endif
