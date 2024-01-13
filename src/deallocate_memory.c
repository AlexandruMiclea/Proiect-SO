#include "../inc/alloc.h"

void deallocate_memory (void* ptr){
    block_metadata* block = get_address_block(ptr);

    // set my current block to be free
    block->free = 1;

    // check if the left block is also free, if yes coalesce
    if (block->next != NULL && check_if_both_free(block, block->next)){
        block = coalesce(block, block->next);
    }

    if (block->prev != NULL && check_if_both_free(block->prev, block)){
        block = coalesce(block->prev, block);
    }

}