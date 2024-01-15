#include "../inc/alloc.h"

void *allocate_clear_memory(size_t cnt, size_t req_size){
    if (req_size <= 0 || cnt <= 0) return NULL;

    // hideous way to check for a possible overflow 
    if (cnt * req_size < 0) return NULL;
    
    block_metadata* block = find_free_block((block_metadata*)heap_begin, req_size * cnt);
    // TODO SEE IF IT IS OK
    //printf("adresa de la care fac memset: %p\n", (void*)block + METADATA_SIZE);
    memset((void*)block + METADATA_SIZE, 0, cnt);

    return (void*)block + METADATA_SIZE;
}