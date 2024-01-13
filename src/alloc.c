#include "../inc/alloc.h"

block_metadata *find_free_block(block_metadata** last, size_t req_size){

    if (heap_begin == NULL) {
        heap_begin = sbrk(0);
        heap_end = sbrk(0);
        return request_space(NULL, req_size);
    }

    block_metadata* pointer = heap_begin;

    while (pointer && !(pointer->free == 1 && pointer->size >= req_size)){
        *last = pointer;
        pointer = pointer-> next;
    }

    if (pointer == NULL)
        return request_space(*last, req_size);
    
    return pointer;
}
    
block_metadata *request_space(block_metadata* last, size_t req_size) {
    block_metadata* new_block = heap_end;
    //new_block->size = 
    size_t required_space = PAGE_ALIGNED_SIZE(req_size + METADATA_SIZE);
    //

    void* res = mmap(heap_end, required_space, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (res == NULL) {
        perror("mmap had a problem in request_space\n");
        exit(-1);
    }

    new_block->size = req_size;
    new_block->next = NULL;
    new_block->prev = NULL;
    new_block->free = 0;

    if (last != NULL){
        last->next = new_block;
        new_block->prev = last;
    }

    heap_end += required_space;

    return new_block;
}