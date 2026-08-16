#pragma once
#include <stddef.h>
//look into opaque structs for complete encapsulation
typedef struct {
    int* data;
    size_t length;
    size_t capacity;
} Vector;

Vector* initVector(size_t capacity);
void destroy(Vector* vector);

void push(Vector* vector, int val);
int pop(Vector* vector);

//not complete
void insert(Vector* vector, size_t index, int val);
//not complete
int removeAt(Vector* vector, size_t index);

size_t memCheck(Vector* vector);
size_t lengthCheck(Vector* vector);

void printVector(Vector* vector);
