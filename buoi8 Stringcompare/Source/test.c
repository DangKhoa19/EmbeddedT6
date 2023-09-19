/*
* File: test.c
* Author: Khoa Tran
* Date: 17/07/2023
* Description: This file contains all the functions/methods to to reversed string
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "test.h"


Compare isEqual(const char arr1[], const char arr2[]) {
    uint8_t i = 0;
    while (arr1[i] == arr2[i]) {
        if (arr1[i] == '\0') {
            return EQUAL;
        }
        i++;
    }
    if (arr1[i] > arr2[i]) {
        return BIGGER;
    } else {
        return SMALLER;
    }
}
