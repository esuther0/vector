#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "vector.h"

int main(void){
    Vector* v = initVector(4); //starting capacity of 4

    printf("appending\n");
    for(int i = 0; i < 10; i++){
        push(v, i);
        printf("%d, size: %zu, memory: %zu\n", v->data[i], lengthCheck(v), memCheck(v));
    }
    
    printVector(v);
    printf("vector length is %zu\n", v->length);
    insert(v, 2, 99);
    printVector(v);

    printf("popping\n");
    for(int i = 0; i < 10; i++){
        printf("%d, size: %zu, memory: %zu\n", pop(v), lengthCheck(v), memCheck(v));
    }

    destroy(v);
}