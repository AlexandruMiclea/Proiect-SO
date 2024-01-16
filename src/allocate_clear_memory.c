#include "../inc/alloc.h"

void *allocate_clear_memory(size_t cnt, size_t req_size){
    if (req_size <= 0 || cnt <= 0) return NULL;

    // hideous way to check for a possible overflow 
    if (cnt * req_size < 0) return NULL;
    
    pthread_mutex_lock(&mutex);
    block_metadata* block = find_free_block((block_metadata*)heap_begin, req_size * cnt);
    memset((void*)block + METADATA_SIZE, 0, cnt);
    pthread_mutex_unlock(&mutex);

    return (void*)block + METADATA_SIZE;
}