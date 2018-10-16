#include "mempool.h"

void pool_init(pool_t *pool) {
    // Initialise the pool
    pool->head = NULL;
}

void *pool_allocate(pool_t *pool) {
    // Return the head of the list of blocks
    // Update the head pointer
    void* oldHead = pool->head;
    pool->head = *((void**)oldHead);
    return oldHead;
    
}

void pool_deallocate(pool_t *pool, void *item) {
    // Add the new item to the head of the list
    void* oldHead = pool->head;
    pool->head = item;
    *((void**)item) = oldHead;
    
}
