#ifndef CLOX_MEMORY_H
#define CLOX_MEMORY_H

#include "common.h"
#include "object.h"

#define ALLOCATE(type, count) \
    ((type*) reallocate(NULL, sizeof(type)*(count)))

#define FREE(type, pointer) reallocate(pointer, 0)

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(pointer, type, capacity) \
    (type*)(reallocate(pointer, (sizeof(type)*(capacity))))

#define FREE_ARRAY(pointer) \
    (reallocate(pointer, 0))

void *reallocate(void *pointer, int newSize);
void freeObjects();

#endif //CLOX_MEMORY_H
