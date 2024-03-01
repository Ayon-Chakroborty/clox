#ifndef wizpp_memory_h
#define wizpp_memory_h

#include "common.h"

#define ALLOCATE(type, count) \
    (type*)reallocate(NULL, 0, sizeof(type)*(count))

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity)*2)

#define GROW_ARRAY(type, pointer, oldCapacity, newCapacity) \
    (type*)reallocate(pointer, sizeof(type)*(oldCapacity), \
        sizeof(type)*(newCapacity))

#define FREE_ARRAY(type, pointer, oldCapacity) \
    reallocate(pointer, sizeof(type) * (oldCapacity), 0)


void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif