#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "vector.h"

int main(void){
    Vector v = initVector(4);

    printf("appending\n");
    for(int i = 0; i < 10; i++){
        push(&v, i);
        printf("%d, size: %d, memory: %d\n", v.data[i], v.length, v.capacity);
    }
    
    printf("popping\n");
    for(int i = 0; i < 10; i++){
        printf("%d, size: %d, memory: %d\n", pop(&v), v.length, v.capacity);
    }

    free(v.data);
}