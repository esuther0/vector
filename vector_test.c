#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "vector.h"


int main(void){
    Vector *v = initVector(4);
    assert(v != NULL);

    for (int i = 0; i < 10; i++) {
        push(v, i);
    }

    assert(getLength(v) == 10);
    assert(getCapacity(v) == 16);

    assert(get(v, 3) == 3);
    set(v, 3, 42);
    assert(get(v, 3) == 42);
    
    //insert test
    insert(v, getLength(v), 99);    
    assert(get(v, getLength(v) - 1) == 99);

    insert(v, 5, 54);
    assert(get(v, 5) == 54);
    
    //removeAt test
    removeAt(v, getLength(v) - 1);
    removeAt(v, 5);
    assert(getLength(v) == 10);
    assert(getCapacity(v) == 16);

    set(v, 3, 3);
    for (int i = 0; i < 10; i++) {
        int val = pop(v);
        assert(val == 9 - i);
    }

    assert(getLength(v) == 0);
    assert(getCapacity(v) == 2);

    destroy(v);

    printf("success\n");
}