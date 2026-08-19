#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

struct Vector {
    int* data;
    size_t length;
    size_t capacity;
};

static void resize(Vector* vector, size_t newCapacity){
    int* tmp = realloc(vector->data, sizeof(int) * newCapacity);
    if(tmp == NULL){
        return;
    } else{
        vector->capacity = newCapacity;
        vector->data = tmp;
    }
}

Vector* initVector(size_t capacity){
    if(capacity == 0){
        return NULL;
    }

    Vector* v = malloc(sizeof(Vector));
    if(v == NULL){
        return NULL;
    }

    v->data = malloc(sizeof(int) * capacity);
    if(v->data == NULL){
        free(v);
        return NULL;
    }

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
    
    //shifting every element above index up 1
    memmove(vector->data + index + 1, 
            vector->data + index, 
            sizeof(int) * (vector->length - index));

    vector->length++;

    vector->data[index] = val;
}

int removeAt(Vector* vector, size_t index){
    if(index == vector->length - 1){
        return pop(vector);
    }

    int val = vector->data[index];

    if((vector->length - 1) * 4 < vector->capacity){
        resize(vector, vector->capacity / 2);
    }

    //shifting every element above index down 1

    memmove(vector->data + index,
            vector->data + index + 1,
            sizeof(int) * (vector->length - index - 1)); 
            
    vector->length--;

    return val;
}

int get(Vector* vector, size_t index){
    return vector->data[index];
}
void set(Vector* vector, size_t index, int val){
    vector->data[index] = val;
}

size_t getCapacity(Vector* vector){
    return vector->capacity;
}

size_t getLength(Vector* vector){
    return vector->length;
}

void printVector(Vector* vector){
    printf("Vector length: %zu\n", getLength(vector));
    printf("Vector memory: %zu\n", getCapacity(vector));
    
    printf("[ ");
    for(int i = 0; i < vector->length; i++){
        if(i < vector->length - 1){
            printf("%d, ", vector->data[i]);
        } else{
            printf("%d ]\n", vector->data[i]);
        }
    }
}