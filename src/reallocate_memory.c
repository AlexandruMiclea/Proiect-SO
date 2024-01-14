#include "../inc/alloc.h"

void *reallocate_memory (void* ptr, size_t req_size){
    if (ptr == NULL && req_size == 0) {
        perror("Tried to resize a NULL pointer to 0");
        exit(1);
    }
    
    if (ptr == NULL) {
        // same as allocate_memory(req_size) per MAN pages
        allocate_memory(req_size);
    }

    if (req_size == 0) {
        // same as deallocate_memory(ptr)
        deallocate_memory(ptr);
    }

    block_metadata* req_block = get_address_block(ptr);

    // first case: shrinking memory
    if (req_block->size >= req_size) {
        return split_residual_memory(req_block, req_size, req_block->size + METADATA_SIZE);
    }

    // second case: increasing memory

    if (req_block->size < req_size){
        // deallocate the current block, get a new free space to accomodate,
        // then use memcpy to cpy from the old position to the new one

        void* new_address = find_free_block((block_metadata*)heap_begin, req_size);
        memcpy(new_address, (void*)req_block + METADATA_SIZE, req_size);
        deallocate_memory(req_block);

        return new_address;
    }
}