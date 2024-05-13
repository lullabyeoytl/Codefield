/*
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
char a[105][105];
int b[105][105];
int c[105][105];
int main()
{
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    scanf("%d%d",&n,&m);
    for(int i= 1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%c",a[i][j]);
            if(a[i][j]=='*')b[i][j]=1;
           
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(a[i][j]=='*')
            {
                printf("*");
            }
            else if(a[i][j]=='?')
            {
                c[i][j]=b[i-1][j]+b[i+1][j]+b[i][j-1]+b[i][j+1]+b[i-1][j+1]+b[i+1][j-1]+b[i-1][j-1]+b[i+1][j+1];
                printf("%d",c[i][j]);
            }
        }
        printf("\n");
    }

     

    
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
bool a[105][105]; 
int main()
{
    memset(a,0,sizeof(a));
    int n,m;
    char tmp;
    cin>>n>>m; 
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=m;j++) 
        {
            cin>>tmp; 
            if(tmp=='*') a[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1) printf("*");  
            else
            {
                printf("%d",a[i+1][j+1]+a[i+1][j-1]+a[i+1][j]+a[i][j+1]+a[i][j-1]+a[i-1][j+1]+a[i-1][j]+a[i-1][j-1]);
                
            }
        }
        printf("\n");
    }
    return 0;
}
