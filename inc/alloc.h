#ifndef ALLOC
#define ALLOC

#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

struct block_meta {
    size_t size;
    struct block_meta *next;
    int free;
    int magic;
};

#define META_SIZE sizeof(struct block_meta)

extern void *global_base = NULL;

struct block_meta *find_free_block(struct block_meta **last, size_t size);
struct block_meta *request_space(struct block_meta* last, size_t size);

void *memal (size_t size);
void *memreal (void* ptr, size_t size);
void *memalcont (size_t cnt, size_t size);
void memdeal (void* ptr);

#endif //ALLOC