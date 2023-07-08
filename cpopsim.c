#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "rng.h"
#include "structs.h"
#include "funcs.h"

Entity *population;

void rngtest(){
    printf("RNG Table Size: %lu\n", sizeof(RngTable));
    RngTable *table = malloc(sizeof(RngTable));
    rand_init();
    rand_maketable(table);
    RngTable oldtable = *table;
    rand_printtable(table);
    //printf("\n%X\n\n", rand_byterng(table));
    for(int i=0;i<16;i++) rand_byterng(table);
    rand_printtable(table);
    // printf("\n%X\n\n", oldtable.values[0]);
    // rand_printtable(table);
    rand_printtablediff(&oldtable, table);
}

int main(){
    population = malloc(sizeof(Entity)*POPULATION_SIZE);
    printf("\n\n"
           "Entity Size: %lu bytes\n"
           "Population Size: %d Entities\n"
           "Total Size: %lu bytes\n", 
           sizeof(Entity), POPULATION_SIZE, sizeof(Entity)*POPULATION_SIZE
    );

    printf("%d\n", firstEmptyPos);
    create_adam_and_eve(population);
    printout(population);
    population[2] = KEYENTITY_ADAM;
    findNextEmpty(population);
    printf("%d\n", firstEmptyPos);
    population[1].age = 0;
    findNextEmpty(population);
    printf("%d\n", firstEmptyPos);

    free(population);

    //rngtest();

    return 0;
}