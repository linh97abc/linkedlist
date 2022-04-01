#ifndef __SYS_MEM_H_
#define __SYS_MEM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct sys_mem
    {                         /* MEMORY CONTROL BLOCK                                      */
        void *mem_free_list;  /* Pointer to list of free memory blocks                     */
        uint32_t blkSize;     /* Size (in bytes) of each block of memory                   */
        uint32_t numBlks;     /* Total number of blocks in this partition                  */
        uint32_t numFreeBlks; /* Number of memory blocks remaining in this partition       */
    };

    /**
     * @brief Create a fixed-sized memory partition that will be managed by uC/OS-II.
     * @param pmem    is a pointer to the memory partition control block
     * @param addr    is the starting address of the memory partition
     * @param size    is the number of memory blocks to create from the partition.
     * @param blksize is the size (in bytes) of each block in the memory partition.
     * @return != (struct sys_mem *)0  is the partition was created
     *         == (struct sys_mem *)0  if the partition was not created because of invalid arguments or, no
     *                              free partition is available.
     */
    struct sys_mem *sys_mem_create(struct sys_mem *pmem, void *addr, uint32_t size, uint32_t blksize);

    /**
     * @brief Get a memory block from a partition
     * @param pmem    is a pointer to the memory partition control block
     * @return A pointer to a memory block if no error is detected
     *         A pointer to NULL if an error is detected
     */
    void *sys_mem_get(struct sys_mem *pmem);

    /**
     * @brief Returns a memory block to a partition
     * @param pmem    is a pointer to the memory partition control block
     * @param pblk    is a pointer to the memory block being released.
     * @param size    is the number of memory blocks to create from the partition.
     * @param blksize is the size (in bytes) of each block in the memory partition.
     * @return 0      if the memory block was inserted into the partition
     *         -1     if you are returning a memory block to an already FULL memory
     *                partition (You freed more blocks than you allocated!)
     */
    int8_t sys_mem_put(struct sys_mem *pmem, void *pblk);

#ifdef __cplusplus
}
#endif

#endif
