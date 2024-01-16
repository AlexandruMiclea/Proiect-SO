#include "../inc/alloc.h"

void* heap_begin = NULL;
void* heap_end = NULL;
bool mutex_is_initialized = false;

pthread_mutexattr_t attr;
pthread_mutex_t mutex;

void init_mutex(){
    if (mutex_is_initialized == false){
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
        pthread_mutex_init(&mutex, &attr);
        pthread_mutexattr_destroy(&attr);
        mutex_is_initialized = true;
    }
}