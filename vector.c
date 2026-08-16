#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "vector.h"

static void resize(Vector* vector, size_t newCapacity){
    vector->capacity = newCapacity;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
}

Vector* initVector(size_t capacity){
    assert(capacity > 0);

    Vector* v = malloc(sizeof(Vector));

    v->data = malloc(sizeof(int) * capacity);
    v->length = 0;
    v->capacity = capacity;
  
    return v;
}

void destroy(Vector* vector){
    free(vector->data);
    free(vector);
}

void push(Vector* vector, int val){
    if(vector->length >= vector->capacity){
        if(vector->capacity == 0){ // aka theres no array
            vector->capacity = 2;
        }

        resize(vector, vector->capacity * 2);
    }

    vector->data[vector->length] = val;
    vector->length++;
}

int pop(Vector* vector){
    assert(vector->length > 0 && "no elements to pop\n");

    vector->length--;

    int val = vector->data[vector->length];

    if(vector->length * 4 < vector->capacity){
        resize(vector, vector->capacity / 2);
        return val;
    } else{
        return val;
    }
}

void insert(Vector* vector, size_t index, int val){
    assert(index <= vector->length);

    if(index == vector->length){
        push(vector, val);
        return;
    }

    if(vector->length >= vector->capacity){
        if(vector->capacity == 0){
            vector->capacity = 2;
        }
            
        resize(vector, vector->capacity * 2);
    }

    vector->length++;

    for(int i = vector->length - 1; i > index; i--){
        vector->data[i] = vector->data[i - 1];
    }

    vector->data[index] = val;
}

size_t memCheck(Vector* vector){
    return vector->capacity;
}

size_t lengthCheck(Vector* vector){
    return vector->length;
}

void printVector(Vector* vector){
    printf("Vector length: %zu\n", lengthCheck(vector));
    printf("Vector memory: %zu\n", memCheck(vector));
    
    printf("[ ");
    for(int i = 0; i < vector->length; i++){
        if(i < vector->length - 1){
            printf("%d, ", vector->data[i]);
        } else{
            printf("%d ]\n", vector->data[i]);
        }
    }
}