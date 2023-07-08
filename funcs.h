#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "rng.h"
#include "structs.h"

#ifndef CPOPSIM_FUNCS
#define CPOPSIM_FUNCS

const Entity KEYENTITY_ADAM = { 130, { 0b10000011 } };
const Entity KEYENTITY_EVE = { 130, { 0b00000011 } };

int firstEmptyPos = 0;

void create_adam_and_eve(Entity *population){
    population[0] = KEYENTITY_ADAM;
    population[1] = KEYENTITY_EVE;
    firstEmptyPos = 2;
}

void findNextEmpty(Entity *population){
    for(int i=0;i<POPULATION_SIZE;i++)
        if(population[i].age < 127){
            firstEmptyPos = i;
            break;
        } 
}

void printout(Entity *population){
    for(int i=0;i<POPULATION_SIZE;i++) 
        if(population[i].age > 127) {
            printf(
                "POS%d: MaxAge %d  Male %d\n", i, 
                population[i].genes.attrib & 7, ( population[i].genes.attrib & ATTRIB_ISMALE ) > 0
            );
        }
}

#endif