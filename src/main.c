#include "../inc/alloc.h"

// daca folosesti adresa lui sbrk ca indicativ pentru malloc, iti arunca pagina unde vrea el
// dar daca adresa e deja aliniata la pagina, mi-o va pune fix langa!

// sa zicem ca mmap o sa aloce mereu in continuare
// deci daca il pun sa imi dea pagini de la heap end e baiat ascultator


int main() {

    int* space = allocate_memory(100);

    block_metadata* pointer = heap_begin;
    while (pointer != NULL){
        printf("%d %d\n", pointer->size, pointer->free);
        pointer = pointer->next;
    }
    printf("\n");

    space = allocate_memory(100);

    pointer = heap_begin;
    while (pointer != NULL){
        printf("%d %d\n", pointer->size, pointer->free);
        pointer = pointer->next;
    }
    printf("\n");

    space = reallocate_memory(space, 20);

    pointer = heap_begin;
    while (pointer != NULL){
        printf("%d %d\n", pointer->size, pointer->free);
        pointer = pointer->next;
    }
    printf("\n");

    space = reallocate_memory(space, 120);

    pointer = heap_begin;
    while (pointer != NULL){
        printf("%d %d\n", pointer->size, pointer->free);
        pointer = pointer->next;
    }
    printf("\n");

    deallocate_memory(space);

    pointer = heap_begin;
    while (pointer != NULL){
        printf("%d %d\n", pointer->size, pointer->free);
        pointer = pointer->next;
    }
    printf("\n");

    space = allocate_clear_memory(3, sizeof(int));

    pointer = heap_begin;
    while (pointer != NULL){
        printf("%d %d\n", pointer->size, pointer->free);
        pointer = pointer->next;
    }
    printf("\n");

    return 0;
}