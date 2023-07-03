#include "types.h"

#ifndef CPOPSIM_STRUCTS
#define CPOPSIM_STRUCTS

typedef struct {
    byte age;
    Genome genes;
} Entity;

typedef struct {
    byte maxage;
} Genome;


#endif