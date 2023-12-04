#include <stdio.h>
#include "inc/alloc.h"

int main() {
    struct block_meta block;
    printf("%ld", sizeof(block));
    memal(1);

    return 0;
}