
// phan vung text
//#include <stdio.h>

//static void display() // static toan cuc
//{
 //   display();
//return 0;
//}
//phan vung data


//#include <stdio.h>

//int i =10;
//static int x=5;

//void tong ()
//{
  //  static int y= 10; 
     //            y=5;
//}

//int main(int argv, char const *argc[])
//{
  //  int a;
  //  i= 20;
   // printf("i= %d\n",i );
   // i=4;
    
//return 0;
//}
//phan vung data




//#include <stdio.h>

//int tong (int a, int b)
//{
    //int c;
    //c =a +b ;
  //      return c;
//}

//int main(int argv, char const *argc[])
//{
   // int x= tong (5,7);      //int a=5;  //0x01
                              //int b=7; //0x02
                              //int c; //0x03
                              //c=a+b; //0x04
                              //return c;

//tong(6,8);            //int a=6 ; //0xc1
                      // int b=7 ;  //0xc2
  
   //printf("x= %d\n",x );
    
    
//return 0;
//}
//phan vung stack



#include <stdio.h>

int swap (int *a, int *b)     //int *a = 0xc1          //0xa1
{                               //int *b = 0xc2         //0xa2
    int temp= *a;  
    *a = *b ;
    *b= temp;
        
}

int main(int argv, char const *argc[])
{
    int x= 10; //0xc1
  
    int y= 20; //0xc2
    swap(&x,&y);
    
    printf("x= %d\ny= %d",x,y );
    
    
return 0;
}

//gia tri cua x, y thay doi nhu sau: 
    //&x lay dia chi cua x 0xc1 =>//int *a = 0xc1 
    //&y lay dia chi cua y 0xc2 //int *b = 0xc2
    //int temp= *a => temp =10 
    //*a = *b        => *a = 20;
    //*b= temp;       => *b= 10
    //=>x=20, y= 10