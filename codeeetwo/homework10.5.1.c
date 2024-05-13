#include <stdio.h>
void delect(char c, char str[])
{
    int j=0;
    for(int i = 0; str[i]!='\0';i++)
    {
        if(str[i]!=c)
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';//勿忘以中止符结尾
    return ;
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