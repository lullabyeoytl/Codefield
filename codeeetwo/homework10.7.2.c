#include <stdio.h>
#include <string.h>
void change(char *ptr)
{
   int len;
   char temp;
   char *pStart;
   char *pEnd;
   len = strlen(ptr);
   for(pStart = ptr,pEnd= ptr+len-1;pStart<pEnd;pStart++,pEnd--)
   {
    temp = *pStart;
    *pStart = *pEnd;
    *pEnd = temp;
   }
}

int main()
{
    char a[80],b[80];
    printf("Input a string: ");
    gets(a);
    change(a);
    printf("%s\n",a);
    return 0;
}