#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "types.h"

#ifndef CPOPSIM_RNG
#define CPOPSIM_RNG

void rand_init(){
    srand(time(NULL));
}

typedef struct {
    byte values[256];
    byte ptr;
} RngTable;

void rand_maketable(RngTable *table){
    for(int i=0;i<256;i++){
        table->values[i] = rand() & 255;
    } 
    table->ptr = 0;
}

void rand_printtable(RngTable *table){
    for(int i=0;i<256;i++){
        printf( (i == table->ptr) ? "%02X* " : "%02x  ", table->values[i]);
        if(i % 16 == 15) printf("\n");
    }
    printf("PTR: %x\n", table->ptr);
}

void rand_printtablediff(RngTable *table0, RngTable *table1){
    for(int i=0;i<256;i++){
        if(table0->values[i] != table1->values[i]) 
            printf("POS%02x: T1:%02x  T2:%02x\n", i, table0->values[i], table1->values[i]);
    }
    printf("PTR: T1:%02x  T2:%02x\n", table0->ptr, table1->ptr);
}

byte rand_byterng(RngTable *table){
    byte x = table->values[table->ptr];
    table->ptr++;
    table->values[x]++;
    return x;
}

short rand_shortrng(RngTable *table){
    return rand_byterng(table) | ( rand_byterng(table) << 8); 
}

#endif