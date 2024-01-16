#include "../inc/alloc.h"

void *allocate_clear_memory(size_t cnt, size_t req_size){
    if (req_size <= 0 || cnt <= 0) return NULL;

    pthread_mutex_lock(&mutex);
    block_metadata* block = find_free_block((block_metadata*)heap_begin, req_size * cnt);
    memset(block + 1, 0, cnt * req_size);
    pthread_mutex_unlock(&mutex);

    return block + 1;
}