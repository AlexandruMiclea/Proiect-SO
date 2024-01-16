#include "../inc/alloc.h"

// daca folosesti adresa lui sbrk ca indicativ pentru malloc, iti arunca pagina unde vrea el
// dar daca adresa e deja aliniata la pagina, mi-o va pune fix langa!

// sa zicem ca mmap o sa aloce mereu in continuare
// deci daca il pun sa imi dea pagini de la heap end e baiat ascultator


int main() {

    // I need to call this method if I am to use these functions across processes
    init_mutex();

    // TEST 1: bi-dimensional matrix

    int processes = 60; // around 65 processes I get seg fault, below that it is safe

    int** addresses = allocate_memory((processes + 1) * sizeof(void*));

    for (int i = 1; i <= processes; i++){
        pid_t pid = fork();
        //printf("%d\n", pid);
        if (pid == 0){
            addresses[i] = allocate_memory(5 * sizeof(int));
            for (int j = 0; j < 5; j++){
                addresses[i][j] = 10 * i + j;
            }
            printf("sunt in copil si am adresa %p\n", addresses[i]);
            return;
        }
    }

    for (int i = 1; i <= processes; i++) {
        wait(NULL);
    }

    for (int i = 1; i <= processes; i++) {
        for (int j = 0; j < 5; j++){
            printf("%d ", addresses[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i <= processes; i++) {
        deallocate_memory(addresses[i]);
    }

    // TEST 2: reallocation
    // I allocate 10 lists of 10 items, all from 1 to 10
    // I then double the memory of each section
    // After that, the contents should be numbers from 1 to 10
    // followed by 10 zeroes

    

    // aici vedem ce a ramas pe heap

    // block_metadata* pointer = heap_begin;
    // while (pointer != NULL){
    //     printf("%p %d %d\n",pointer, pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }
    // printf("\n");

    // test allocate_memory on 3 processes

    // int* space = allocate_memory(4037);

    // block_metadata* pointer = heap_begin;
    // while (pointer != NULL){
    //     printf("%p %d %d\n",pointer, pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }
    // printf("\n");

    // space = allocate_memory(100);

    // pointer = heap_begin;
    // while (pointer != NULL){
    //     printf("%p %d %d\n",pointer, pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }
    // printf("\n");

    // space = reallocate_memory(space, 20);

    // pointer = heap_begin;
    // while (pointer != NULL){
    //     printf("%p %d %d\n",pointer, pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }
    // printf("\n");

    // space = reallocate_memory(space, 120);

    // pointer = heap_begin;
    // while (pointer != NULL){
    //     printf("%p %d %d\n",pointer, pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }
    // printf("\n");

    // deallocate_memory(space);

    // pointer = heap_begin;
    // while (pointer != NULL){
    //     printf("%p %d %d\n",pointer, pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }
    // printf("\n");

    // space = allocate_clear_memory(3, sizeof(int));

    // pointer = heap_begin;
    // while (pointer != NULL){
    //     printf("%p %d %d\n",pointer, pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }
    // printf("\n");

    // for(int i = 0; i < 3; i++) {
    //     printf("%d ", space[i]);
    // }

    // printf("%p\n", space);
    // deallocate_memory(space);

    // pointer = heap_begin;
    // while (pointer != NULL){
    //     printf("%p %d %d\n",pointer, pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }
    // printf("\n");

    // deallocate_memory(heap_begin);

    // pointer = heap_begin;
    // while (pointer != NULL){
    //     printf("%p %d %d\n",pointer, pointer->size, pointer->free);
    //     pointer = pointer->next;
    // }
    // printf("\n");

    return 0;
}