#include <cstdio>
#include <cstring>
char a[110];char b[110];char c[110];char d[110];int res[30];
int main(void)
{
    memset (res , 0 , sizeof(res));
    gets(a); gets(b); gets(c); gets(d);
    for(int i = 0 ; i <= strlen(a) -1 ; i++)
    {
        if(a[i] >= 'A' && a[i] <= 'Z')
         res[a[i]-64]++ ;
    }
    for(int i = 0 ; i <= strlen(b) -1 ; i++)
    {
        if(b[i] >= 'A' && b[i] <= 'Z')
         res[b[i]-64]++ ;
    }
    for(int i = 0 ; i <= strlen(c) -1 ; i++)
    {
        if(c[i] >= 'A' && c[i] <= 'Z')
         res[c[i]-64]++ ;
    }
    for(int i = 0 ; i <= strlen(d) -1 ; i++)
    {
        if(d[i] >= 'A' && d[i] <= 'Z')
         res[d[i]-64]++ ;
    }
    int max = -1;
    for(int p = 1 ; p<=26 ; p++)
    {
        if(res[p] >= max)
        max = res[p];
    }
    for(int q = max ; q>=1; q--)
    {
        for(int r = 1 ; r<=25 ; r++)
        {
            if(res[r] >= q )
             printf("* ");
             else
            printf("  ");
        }
        if(res[26] >= q)
        printf("*\n");
        else
        printf(" \n");
    }
    for(int r = 1 ; r<=25 ; r++)
    printf("%c " , 'A'+r-1);
    printf("Z");
    return 0;
}