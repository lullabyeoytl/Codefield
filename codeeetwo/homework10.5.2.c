#include <stdio.h>
#include <string.h>
void delect(char c, char *s)
{
    char str[100];
    char *t=str;
    strcpy(t,s);
    for( ; *t!='\0';t++)
    {
        if(*t!=c)
        {
            *s=*t;
            s++;
        }
    }
    *s = '\0';
}
int main()
{
    char str[100],ch;
    printf("Input your string: ");
    gets(str);
    printf("Input character ");
    ch=getchar();
    delect(ch,str);
    printf("%s\n",str);
    return 0;
}