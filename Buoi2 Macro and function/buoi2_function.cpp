//#include <stdio.h>

//#define MAX 10
//#define tong(a,b)a+b
//#define create_func(name_func, cmd)
//void name_func()
//{
  //  printf("%s\n", (char *)cmd);
//}
//create_func(test,"Hello");
//create_func(test2,"Chao");
//int main(int argc, char const *argv[])
//{
  //   test();
 //    test2();
 //   return 0;
//}

#include <stdio.h>

#define MAX 10
#define tong(a, b) ((a) + (b))
#define create_func(name_func, cmd)\
void name_func() \
{ printf("%s\n", cmd); }

create_func(test, "Hello");
create_func(test2, "Chao");

int main(int argc, char const *argv[])
{
    test();
    test2();
    return 0;
}