#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "test.h"

int main() {
    char arr1[] = "Hello11";
    char arr2[] = "Hello";
    Compare result = isEqual(arr1, arr2);
    
    if (result == BIGGER) {
        printf("arr1 is bigger than arr2.\n");
    } else if (result == SMALLER) {
        printf("arr1 is smaller than arr2.\n");
    } else {
        printf("arr1 is equal to arr2.\n");
    }
    
    return 0;
}

