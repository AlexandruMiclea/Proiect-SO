#include "../inc/alloc.h"

void *reallocate_memory (void* ptr, size_t req_size){
    if (ptr == NULL && req_size == 0) {
        perror("Tried to resize a NULL pointer to 0");
        exit(1);
    }
    
    if (ptr == NULL) {
        // same as allocate_memory(req_size) per MAN pages
        allocate_memory(req_size);
        return NULL;
    }

    if (req_size == 0) {
        // same as deallocate_memory(ptr)
        deallocate_memory(ptr);
        return NULL;
    }

    pthread_mutex_lock(&mutex);
    block_metadata* req_block = get_address_block(ptr);

    // first case: shrinking memory
    if (req_block->size >= req_size) {

        void* address = split_residual_memory(req_block, req_size, req_block->size + METADATA_SIZE);
        pthread_mutex_unlock(&mutex);

        return address;
    }

    // second case: increasing memory

    if (req_block->size < req_size){
        // free the current block, get a new free space to accomodate,
        // then use memcpy to cpy from the old position to the new one

        block_metadata* new_address = find_free_block((block_metadata*)heap_begin, req_size);
        memcpy(new_address + 1, req_block + 1, req_block->size);
        req_block->free = 1;
        pthread_mutex_unlock(&mutex);

        return new_address + 1;
    }
    return NULL; // should never happen
}