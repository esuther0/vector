#pragma once
#include <stddef.h>

typedef struct Vector Vector;

Vector* initVector(size_t capacity);
void destroy(Vector* vector);

void push(Vector* vector, int val);
int pop(Vector* vector);

//naive solutions for these two, look into memmove
void insert(Vector* vector, size_t index, int val);
int removeAt(Vector* vector, size_t index);

int get(Vector* vector, size_t index);
void set(Vector* vector, size_t index, int val);

size_t getCapacity(Vector* vector);
size_t getLength(Vector* vector);

void printVector(Vector* vector);
