#include <stdio.h>

void tong (int a, int b)
{
    printf("Tong cua %d va %d la= %d\n", a,b,a+b);
}
int main (int argv, char const *argc[])
{
    void (*ptr)(int,int);
    ptr=&tong;
    ptr(71,8);
    
    printf("Dia chi %d\n",ptr);
    return 0;
}
