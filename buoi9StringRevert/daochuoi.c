

#include<stdio.h>
#include<string.h>

void hienthi(char s[100][20], int n)
{
    printf("Mang sau khi dao");
    for(int i=n-1;i>=0;i--)
    {
        printf("%s  ",s[i]);
        }
    
}
void tachtu(char *s)
{
char res[100][20];
int n;
int i=0;
char *p;
const char *delim =" ,.\t\n";
for(p=strtok(s,delim);p!=NULL;p=strtok(NULL,delim))
{
    if(i<100){
strncpy(res[i],p,sizeof(res[i])-1);
res[i][sizeof(res[i])-1]='\0';
i++;
}
}
hienthi(res,i);
}


int main()
{
char s[1000];
 printf("Nhap chuoi ki tu");
fgets(s,sizeof(s),stdin);
tachtu(s);
return 0;
}