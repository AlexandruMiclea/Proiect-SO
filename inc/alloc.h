#ifndef ALLOC_H
#define ALLOC_H

#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <bits/mman-linux.h>
#include <stdbool.h>

// the linked list will be arranged as follows:

/*
--------------------------------------------------------        --------------------------------------------------------
|            |                                         |        |            |                                         |
|  metadata  |          size bytes of memory           |   ->   |  metadata  |          size bytes of memory           |
|            |                                         |        |            |                                         |
--------------------------------------------------------        --------------------------------------------------------
*/

typedef struct block_metadata {
    int free;
    size_t size;
    struct block_metadata *next;
    struct block_metadata *prev;
} block_metadata;

#define METADATA_SIZE sizeof(block_metadata)
#define PAGE_ALIGNED_SIZE(x) (((x) + 0x0FFF) & 0xF000)

extern void *heap_begin;
extern void *heap_end;

block_metadata *find_free_block(block_metadata* last, size_t req_size);
block_metadata *request_space(block_metadata* last, size_t req_size);
// a block, the space 
block_metadata *split_residual_memory(block_metadata* block, size_t occupied_size, size_t total_space);
block_metadata *insert_block_between(block_metadata* new, block_metadata* left, block_metadata* right);
bool check_if_both_free(block_metadata* left, block_metadata* right);
block_metadata* coalesce(block_metadata* left, block_metadata* right);
block_metadata* get_address_block(void* address);

// the four methods of interest

void *allocate_memory (size_t req_size);
void *reallocate_memory (void* ptr, size_t req_size);
void *allocate_clear_memory(size_t cnt, size_t req_size);
void deallocate_memory (void* ptr);

#endif /*ALLOC_H*/