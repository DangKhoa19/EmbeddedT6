#include<stdio.h>
#include<stdint.h>


int main (int argv, char const *argc[])
{
    int i=10;
    
    char c= 'A';

    double d= 10.4;

    void *ptr;

    ptr = &i;

    printf("Dia chi i= %p, gia tri %d\n", ptr, *(int *)ptr);

    ptr = &c;

    printf("Dia chi c= %p, gia tri %c\n", ptr, *(char *)ptr);

    ptr = &d;

    printf("Dia chi d= %p, gia tri %f\n", ptr, *(double *)ptr);
    return 0;

}


//ket qua:
//Dia chi i= 0061FF18, gia tri 10
//Dia chi c= 0061FF17, gia tri A
//Dia chi d= 0061FF08, gia tri 10.400000