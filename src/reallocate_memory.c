#include "../inc/alloc.h"

void *reallocate_memory (void* ptr, size_t req_size){
    if (ptr == NULL && req_size == 0) {
        perror("Tried to resize a NULL pointer to 0");
        exit(1);
    }
    
    if (ptr == NULL) {
        // same as allocate_memory(req_size) per MAN pages
        pthread_mutex_lock(&mutex);
        allocate_memory(req_size);
        pthread_mutex_unlock(&mutex);
        return;
    }

    if (req_size == 0) {
        // same as deallocate_memory(ptr)
        pthread_mutex_lock(&mutex);
        deallocate_memory(ptr);
        pthread_mutex_unlock(&mutex);
        return;
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

        void* new_address = find_free_block((block_metadata*)heap_begin, req_size);
        memcpy(new_address + METADATA_SIZE, (void*)req_block + METADATA_SIZE, req_block->size);
        req_block->free = 1;
        pthread_mutex_unlock(&mutex);

        return new_address + METADATA_SIZE;
    }
}