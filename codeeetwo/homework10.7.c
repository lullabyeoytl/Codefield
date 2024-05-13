#include <stdio.h>
#include <string.h>
void change(char str[], char ptr[])
{
    int len,i,j;
    len = strlen(str);
    for(i=0,j=len-1;str[i]!='\0';i++,j--)
    {
        ptr[j] = str[i];
    }
    ptr[i] = '\0';
}

int main()
{
    char a[80],b[80];
    printf("Input a string: ");
    gets(a);
    change(a,b);
    printf("%s\n",b);
    return 0;
}