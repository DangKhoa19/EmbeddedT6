#ifndef __TEST_H
#define __TEST_H
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    BIGGER,
    SMALLER,
    EQUAL
} Compare;
Compare isEqual(const char arr1[], const char arr2[]);



#endif
