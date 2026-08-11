#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "vector.h"

Vector initVector(size_t capacity){
    assert(capacity > 0);
    return (Vector) {
        .data = malloc(sizeof(int) * capacity),
        .length = 0,
        .capacity = capacity
    };
}

void push(Vector* vector, int val){
    if(vector->length >= vector->capacity){
        if(vector->capacity == 0){ // aka theres no array
            vector->capacity = 2;
        } else{
            vector->capacity *= 2;

            vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
        }
    }

    vector->data[vector->length] = val;
    vector->length++;
}

int pop(Vector* vector){
    assert(vector->length >= 0 && "no elements to pop\n");

    if((--vector->length + 1) * 4 < vector->capacity){
        vector->capacity /= 4;
        vector->data = realloc(vector->data, sizeof(int) * (vector->capacity));
        return vector->data[vector->length];
    } else{
        return vector->data[vector->length];
    }
}
