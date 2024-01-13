#include "../inc/alloc.h"

// daca folosesti adresa lui sbrk ca indicativ pentru malloc, iti arunca pagina unde vrea el
// dar daca adresa e deja aliniata la pagina, mi-o va pune fix langa!

// sa zicem ca mmap o sa aloce mereu in continuare
// deci daca il pun sa imi dea pagini de la heap end e baiat ascultator


int main() {

    printf("Inceput heap: 0x%X\n", heap_begin);
    printf("Sfarsit heap: 0x%X\n", heap_end);
    int* smek = allocate_memory(2*getpagesize());
    printf("adresa alloc: 0x%X\n", smek);
    printf("Inceput heap: 0x%X\n", heap_begin);
    printf("Sfarsit heap: 0x%X\n", heap_end);
    int* smek2 = allocate_memory(sizeof(int) * 3);
    printf("adresa alloc: 0x%X\n", smek2);
    printf("Inceput heap: 0x%X\n", heap_begin);
    printf("Sfarsit heap: 0x%X\n", heap_end);

    return 0;
}