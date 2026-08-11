#pragma once
#include <stddef.h>

typedef struct {
    int* data;
    size_t length;
    size_t capacity;
} Vector;

Vector initVector(size_t capacity);

void push(Vector* vector, int val);

int pop(Vector* vector);

