#include "../inc/alloc.h"
#include <stdio.h>
#include <sys/wait.h>

int main() {

    // I need to call this method if I am to use these functions across processes
    init_mutex();
    int processes = 60; // around 65 processes I get seg fault, below that it is safe

    // TEST 1: bi-dimensional matrix
    // concurrently allocate a bidimensional matrix
    // print its values
    // then deallocate the pointers concurrently

    // int** addresses = allocate_memory((processes + 1) * sizeof(int*));

    // for (int i = 1; i <= processes; i++){
    //     pid_t pid = fork();
    //     //printf("%d\n", pid);
    //     if (pid == 0){
    //         addresses[i] = allocate_memory(5 * sizeof(int));
    //         for (int j = 0; j < 5; j++){
    //             addresses[i][j] = 10 * i + j;
    //         }
    //         return 0;
    //     }
    // }

    // for (int i = 1; i <= processes; i++) {
    //     wait(NULL);
    // }

    // for (int i = 1; i <= processes; i++) {
    //     for (int j = 0; j < 5; j++){
    //         printf("%d ", addresses[i][j]);
    //     }
    //     printf("\n");
    // }

    // for (int i = 1; i <= processes; i++){
    //     pid_t pid = fork();
    //     //printf("%d\n", pid);
    //     if (pid == 0){
    //         deallocate_memory(addresses[i]);
    //         return 0;
    //     }
    // }

    // for (int i = 1; i <= processes; i++) {
    //     wait(NULL);
    // }

    //deallocate_memory(addresses);

    // TEST 2: reallocation
    // I allocate 10 lists of 10 items, all from 1 to 10
    // I then double the memory of each section
    // After that, the contents should be numbers from 1 to 10
    // followed by 10 zeroes

    // int** addresses = allocate_memory(10 * sizeof(int*));

    // for (int i = 0; i < 10; i++) {
    //     pid_t pid = fork();
    //     if (pid == 0) {
    //         addresses[i] = allocate_memory(10 * sizeof(int));
    //         for (int j = 0; j < 10; j++){
    //             addresses[i][j] = j + 1;
    //         }
    //         return 0;
    //     }
    // }

    // for (int i = 0; i < 10; i++) {
    //     wait(NULL);
    // }

    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++){
    //         printf("%d ", addresses[i][j]);
    //     }
    //     printf("\n");
    // }

    // for (int i = 0; i < 10; i++) {
    //     pid_t pid = fork();
    //     if (pid == 0) {
    //         addresses[i] = reallocate_memory(addresses[i], 20 * sizeof(int));
    //         return 0;
    //     }
    // }

    // for (int i = 0; i < 10; i++) {
    //     wait(NULL);
    // }

    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 20; j++){
    //         printf("%d ", addresses[i][j]);
    //     }
    //     printf("\n");
    // }

    // TEST 3: clear allocation
    // I allocate a big list of random data
    // I then free said list, and do a clear allocation of 10 smaller lists
    // The contents of these lists should be 0 all across

    // int* data = allocate_memory(100 * sizeof(int));

    // for (int i = 0; i < 100; i++) {
    //     data[i] = 0xDEADBEEF;
    // }

    // for (int i = 0; i < 100; i++) {
    //     printf("%d\n", data[i]);
    // }

    // deallocate_memory(data);

    // int** addresses = allocate_clear_memory(10, sizeof(int*));

    // for (int i = 0; i < 10; i++) {
    //     pid_t pid = fork();
    //     if (pid == 0) {
    //         addresses[i] = allocate_clear_memory(10, sizeof(int));
    //         return;
    //     }
    // }

    // for (int i = 0; i < 10; i++) {
    //     wait(NULL);
    // }

    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++){
    //         printf("%d ", addresses[i][j]);
    //     }
    //     printf("\n");
    // }

    // RANDOM TESTS DURING DEVELOPMENT


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