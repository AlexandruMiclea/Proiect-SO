#include <stdio.h>
#include "../lib/alloc.h"

int main() {
    struct block_meta block;
    printf("%ld", sizeof(block));
    return 0;
}