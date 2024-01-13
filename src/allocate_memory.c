#include "../inc/alloc.h"

// TODO code goes here

void *allocate_memory (size_t req_size){
    if (req_size <= 0) return NULL;
    
    block_metadata* block = find_free_block((block_metadata**)heap_begin, req_size);

    return (void*)block + METADATA_SIZE;
}