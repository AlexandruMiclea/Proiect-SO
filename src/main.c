#include "../inc/alloc.h"

// daca folosesti adresa lui sbrk ca indicativ pentru malloc, iti arunca pagina unde vrea el
// dar daca adresa e deja aliniata la pagina, mi-o va pune fix langa!

// sa zicem ca mmap o sa aloce mereu in continuare
// deci daca il pun sa imi dea pagini de la heap end e baiat ascultator


int main() {

    // int* first_alloc = allocate_memory(100);
    // printf("adresa heap: 0x%X\n", heap_begin);
    // printf("sfarsit heap: 0x%X\n", heap_end);
    // printf("adresa alloc: 0x%X\n", first_alloc);
    // printf("dimensiune metadata: 0x%X\n", METADATA_SIZE);
    // printf("adresa metadata alloc: 0x%X\n", get_address_block(first_alloc));

    // printf("Inceput heap: 0x%X\n", heap_begin);
    // printf("Sfarsit heap: 0x%X\n", heap_end);
    // int* smek = allocate_memory(getpagesize() - 2*METADATA_SIZE -1);

    // block_metadata* block_head = smek - 8;

    // block_metadata* pointer = block_head;
    // while (pointer != NULL){
    //     printf("%d %d\n", pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }

    // printf("Inceput heap: 0x%X\n", heap_begin);
    // printf("Sfarsit heap: 0x%X\n", heap_end);

    // int* smek2 = allocate_memory(1);

    // pointer = block_head;
    // while (pointer != NULL){
    //     printf("%d %d\n", pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }

    // printf("adresa alloc: 0x%X\n", smek2);
    // printf("Inceput heap: 0x%X\n", heap_begin);
    // printf("Sfarsit heap: 0x%X\n", heap_end);
    // int* smek2 = allocate_memory(sizeof(int) * 3);
    // printf("adresa alloc: 0x%X\n", smek2);
    // printf("Inceput heap: 0x%X\n", heap_begin);
    // printf("Sfarsit heap: 0x%X\n", heap_end);

    // pointer = block_head;
    // while (pointer != NULL){
    //     printf("%d %d\n", pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }

    int* first_alloc = allocate_memory(100);
    int* second_alloc = allocate_memory(100);
    int* third_alloc = allocate_memory(100);

    deallocate_memory(second_alloc);

    block_metadata* pointer = heap_begin;
    while (pointer != NULL){
        printf("%d %d\n", pointer->size, pointer->free);
        pointer = pointer->next;
    }

    deallocate_memory(first_alloc);

    pointer = heap_begin;
    while (pointer != NULL){
        printf("%d %d\n", pointer->size, pointer->free);
        pointer = pointer->next;
    }

    deallocate_memory(third_alloc);

    pointer = heap_begin;
    while (pointer != NULL){
        printf("%d %d\n", pointer->size, pointer->free);
        pointer = pointer->next;
    }

    return 0;
}