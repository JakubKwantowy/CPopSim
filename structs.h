#include "types.h"

#ifndef CPOPSIM_STRUCTS
#define CPOPSIM_STRUCTS

typedef struct {
    byte attrib;
} Genome;

typedef struct {
    byte age; // if MSB is 1 then entity is alive
    Genome genes;
} Entity;

#endif