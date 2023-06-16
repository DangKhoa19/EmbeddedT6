//#include<stdio.h>
//#include<stdint.h>

//typedef union{
// uint8_t varl; //  1 byte
 //uint64_t var2; // 8 byte
 //uint32_t var3; // 3 byte
//}typeData;

//int main (int argv, char const *argc[])
//{
 //   typeData data;
  //  printf("size= %d\n",sizeof(typeData));
  //  printf("Diachi %p\n",&data);
  //  printf("Diachi var1: %p\n", &(data.varl));
  //  printf("Diachi var2: %p\n", &(data.var2));
   // printf("Diachi var3: %p\n", &(data.var3));
//return 0;
//}



//#include<stdio.h>
//#include<stdint.h>

//typedef union{
 //uint8_t varl[6]; //  1 byte
 //uint8_t var2[4]; // 8 byte
 //uint8_t var3[2]; // 3 byte
//}typeData;

//int main (int argv, char const *argc[])
//{
    
 //   typeData data;

  //  for(int i=0;i<6;i++)
   // {
 //       data.varl[i] = i;
  //  }
 //for(int i=0;i<4;i++)
  //  {
  //      data.var2[i] = 2*i;
  //  }
 //for(int i=0;i<2;i++)
  //  {
  //      data.var3[i] = 3*i;
 //   }
// for(int i=0;i<6;i++)
   // {
  //      printf("var1= %d\n",data.varl[i]);
   // }

   
//return 0;
//}


//#include<stdio.h>
//#include<stdint.h>
//#include<string.h>

//typedef union{
// uint8_t varl[6]; //  1 byte
// uint8_t var2[4]; // 8 byte
 //uint8_t var3[2]; // 3 byte
//}typeData;

//typedef union
//{
  //  struct
  //  {
  //      char Id[2];
  //      char Data[3];
  //      char Cs[1];
      
  //  }data;
 //   uint8_t array[5];
//}DataFrame;

//int main (int argv, char const *argc[])
//{
    
 // DataFrame DataFrame;
 // strcpy(DataFrame.data.Id, (char*)"12");

 //  return 0;

//}



#include<stdio.h>
#include<stdint.h>
#include<string.h>

typedef union{
 uint8_t varl[6]; //  1 byte
 uint8_t var2[4]; // 8 byte
 uint8_t var3[2]; // 3 byte
}typeData;

typedef union
{
    struct
    {
        uint8_t Id[2];
        uint8_t Data[3];
        uint8_t Cs[1];
      
    }data;
    uint8_t array[5];
}DataFrame;

int main (int argv, char const *argc[])
{
    
  DataFrame DataFrame;
  DataFrame.data.Id[0]=0x01;
  DataFrame.data.Id[0]=0x02;

  DataFrame.data.Id[0]=0xC1;
  DataFrame.data.Id[1]=0xC2;
  DataFrame.data.Id[2]=0xC3;

  DataFrame.data.Id[0]=0xC8;
   return 0;

}
