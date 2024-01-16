# alloc

My first attempt at a Virtual Memory Manager. The equivalent of the malloc(), calloc(), realloc() and free() functions will
receive the names allocate_memory(), allocate_clear_memory(), reallocate_memory() and deallocate_memory(). Can be called
by multiple processes, and ensure proper allocation of memory blocks, and the returning of distinct pointers.

## References

- https://www.youtube.com/watch?v=sZ8GJ1TiMdk - Writing My Own Malloc in C
- https://github.com/tsoding/memalloc/ - GitHub repo for the above video
- https://danluu.com/malloc-tutorial/ - Warmup code
- https://www.reddit.com/r/learnprogramming/comments/bjnp4m/makefile_placing_objects_in_separate_directory/ - Makefile help
- https://wiki.osdev.org/Category:Memory_management - More in-depth guides
- https://www.cs.usfca.edu/~mmalensek/cs326/assignments/project-3.html - Similar project 

## Implementation details

Double linked list, where the beginning of each block contains 32 bytes of metadata, immediately followed by the memory required
The metadata contains information about the size of the block, pointers to the previous and next nodes in the list, and the value
of its status (0 for occupied, 1 for free).

When deallocating a block, the neighbors of the node are checked if free. If so, they are coalesced into one big block that can be later
used for following allocations.

To ensure proper return of address pointers while multiprocessing, an interprocess mutex object is implemented, initalized with the init_mutex() function.

## Bugs

As is the tradition when attempting such a task, it is imperative to include a list of possible bugs.

- No proper block alignment
- No POSIX standard code
- It is not known to compile with other compilers other than gcc, gnu11 standard
- A lot of void* pointer arithmetic
- I can still write to freed memory zones
- I can write over the block metadata, potentially corrupting my list
- No free list, so at some point allocations can be slow

## How to run

```
$ make
$ make run
```