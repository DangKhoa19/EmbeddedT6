#include<stdio.h>
#include<stdint.h>


int main (int argv, char const *argc[])
{
    char a = 'A';
    int *ptr = &a;
    printf("Dia chi %d\n",*ptr);
    return 0;
}



