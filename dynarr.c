#include <stdio.h>
#include <stdlib.h>

#define IA_RSZ 10 

struct int_array {
    int *items;
    int count;
    int size;
};


struct int_array *arr_new(int size) {
    struct int_array *arr = malloc(sizeof(struct int_array));
    arr->items = malloc(sizeof(int) * size);
    arr->count = 0;
    arr->size = size;
    return arr;
}

int arr_get(struct int_array *arr, int i) {
    return arr->items[i];
}

void arr_ins(struct int_array *arr, int val) {
    if (arr->count < arr->size) {
        arr->items[arr->count] = val;
        arr->count++; 
    } else {
        int i;
        int *new_items = malloc(sizeof(int) * (arr->size + IA_RSZ));
        for (i = 0; i < arr->count; i++) {
            new_items[i] = arr->items[i];
        }
        free(arr->items);
        arr->items = new_items;
        arr->items[arr->count] = val;
        arr->count++; 
        arr->size += 10;
    }
}

int main() {
    int i;
    struct int_array *arr = arr_new(0);

    for (i = 0; i < 30; i++) {
        arr_ins(arr, i+1);
    }

    for (i = 0; i < arr->count; i++) {
        printf("%d\n", arr_get(arr, i));
    } 

    free(arr->items);
    free(arr);
    return 0;
}
