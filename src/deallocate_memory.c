#include "../inc/alloc.h"

void deallocate_memory (void* ptr){
    if(ptr == NULL){
        perror("Tried to deallocate with NULL as parameter.");
        exit(1);
    }
    pthread_mutex_lock(&mutex);
    block_metadata* block = get_address_block(ptr);

    // check if the block is free already
    if (block->free == 1){
        printf("%p %p\n", (void*)block, ptr);
        perror("Requested deallocation block is already free.");
        exit(1);
    }

    // set the current block to be free
    block->free = 1;

    // check if the right block is also free, if yes coalesce
    if (block->next != NULL && check_if_both_free(block, block->next)){
        block = coalesce(block, block->next);
    }

    // check if the left block is also free, if yes coalesce
    if (block->prev != NULL && check_if_both_free(block->prev, block)){
        block = coalesce(block->prev, block);
    }

    return_to_heap(block);
    pthread_mutex_unlock(&mutex);
}