#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "vector.h"


int main(void){
    Vector *v = initVector(4);

    printf("appending\n");
    for (int i = 0; i < 10; i++) {
        push(v, i);

        printf(
            "%d, size: %zu, memory: %zu\n",
            get(v, i),
            getLength(v),
            getCapacity(v)
        );
    }

    printVector(v);

    printf("testing set/get\n");
    printf("index 3 before set: %d\n", get(v, 3));

    set(v, 3, 42);

    printf("index 3 after set: %d\n", get(v, 3));

    printf("testing insert/remove\n");

    insert(v, getLength(v), 99);
    printf("last element after insert: %d\n", get(v, getLength(v) - 1));

    removeAt(v, getLength(v) - 1);
    printVector(v);

    printf("popping\n");
    for (int i = 0; i < 10; i++) {
        int val = pop(v);

        printf(
            "%d, size: %zu, memory: %zu\n",
            val,
            getLength(v),
            getCapacity(v)
        );
    }

    destroy(v);
}