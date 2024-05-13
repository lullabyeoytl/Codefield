#include <bits/stdc++.h>
char a [1000];
char temp[100];
int min(int a,int b)
{
    if(a<=b)return a;
    else return b;
}
void strca(char  s1[] , char s2[], int n1,int n2)
{
    int minn = min(n1,n2);
    int i,j;
    for(i=n1-1,j=0;i>=n1-minn,j<=minn-1;i--,j++)
    {
        if(s1[i]==s2[j])
        continue;
        else
        break;
    }
    for(int k = n1-j,t = 0;t<=n2-1;k++,t++)
    {
        s1[k] = s2[t];
    }
    s1[n1+n2-j] = '\0';

}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i = 1;i<=n;i++)
    {
        if(i==1)
        gets(a);
        if(i>=2)
        {
            getchar();
            gets(temp);
            strca( a, temp,strlen(a),strlen(temp));
        }
    }
    printf("%d",strlen(a));
    return 0;
    
    
}