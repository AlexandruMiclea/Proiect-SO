#include "../inc/alloc.h"

block_metadata *find_free_block(block_metadata* last, size_t req_size){

    if (heap_begin == NULL) {
        heap_begin = sbrk(0);
        heap_end = sbrk(0);
        return request_space(NULL, req_size);
    }

    block_metadata* pointer = heap_begin;

    while (pointer && !(pointer->free == 1 && pointer->size >= req_size)){
        last = pointer;
        //last->free = pointer->free;
        pointer = pointer-> next;
    }

    if (pointer == NULL)
        return request_space(last, req_size);
    
    return split_residual_memory(pointer, req_size, pointer->size + METADATA_SIZE);
}
    
block_metadata *request_space(block_metadata* last, size_t req_size) {
    block_metadata* new_block = heap_end;

    // required_space will always be a multiple of page_size
    size_t required_space = PAGE_ALIGNED_SIZE(req_size + METADATA_SIZE);

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

    heap_end += (size_t)required_space;

    return split_residual_memory(new_block, req_size, required_space);
}

// if I enter this method, I need to make sure I have enough space to accomodate
block_metadata *split_residual_memory(block_metadata* block, size_t occupied_size, size_t total_space) {
    
    if (occupied_size + 2 * METADATA_SIZE < total_space){
        // pointer arithmetic
        block_metadata* new_free_block = block + (occupied_size + METADATA_SIZE) / METADATA_SIZE;   
        // in all the required space I place my metadata nodes and the actual memory I use
        new_free_block-> size = total_space - occupied_size - 2 * METADATA_SIZE;
        new_free_block->prev = block;
        new_free_block->free = 1;
        block->next = new_free_block;
        block->size = occupied_size;
    }

    block->free = 0;
    return block;
}

bool check_if_both_free(block_metadata* left, block_metadata* right){
    return (left->free == 1 && right->free == 1);
}

block_metadata* coalesce(block_metadata* left, block_metadata* right){
    // both are free

    left->size += right->size + METADATA_SIZE;
    if (right->next != NULL)
        right->next->prev = left;
    left->next = right->next;

    return left;
}

block_metadata* get_address_block(void* address){
    block_metadata* pointer = heap_begin;
    if (heap_begin <= address && address <= heap_end){

        while (pointer && ((size_t)pointer + pointer->size <= address)){
            pointer = pointer-> next;
        }

        if (pointer == NULL) {
            perror("somehow no pointer leads to address i want to free");
            exit(1);
        }
    } else {
        perror("invalid address given to free");
        exit(1);
    }
    return pointer;
}