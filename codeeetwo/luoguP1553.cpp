#include <cstdio>
#include <cstring>
char a[25];
int main(void)
{
    gets(a);
    if (a[0] == '0' && strlen(a) == 1)
    printf("0");
    int s; 
    for(s = 0; s<= strlen(a); s++)
    {
        if (a[s] >'9' || a[s] < '0' )
        break;
    }
    //a[s]为第一位非数;
    int i = s-1;
    for( ; i>= 0 ; i--)
    {
        if(a[i] != '0')
        break;
    }
    for(int j = i; j>=0 ; j-- )
    printf("%c" , a[j]);
    if(s != strlen(a))
    printf("%c" , a[s]);
   
    if(a[strlen(a) -1]  >= '0' && a[strlen(a) -1]  <= '9')
    {
        int q;
        for(q = s+1 ; q <= strlen(a) ; q++)
        {
            if(a[q] != '0' )
            break;
        }
        int p;
        for( p = strlen(a) - 1 ; p >= s+1 ; p--)
        if(a[p] != '0')
        break;
        for(int j = p ; j>= q ; j--)
        printf("%c" , a[j]);
    }

    return 0;
}