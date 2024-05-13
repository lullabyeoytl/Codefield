#include <bits/stdc++.h>
using namespace std;
__int128 dp[82][82][82];
__int128 a[82][82];
inline __int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void write(__int128 x)
{
    if(x>9) write(x/10); 
    putchar(x%10+'0'); 
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=n;k++)
            {
                dp[k][i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=read();
            dp[i][j][j]=a[i][j];
        }
    }
    for(int s=1;s<=n;s++)
    {
    for(int len=2;len<=m;len++)
    {
        for(int i=1;i<=m-len+1;i++)
        {
            int j=i+len-1;
            for(int k=i;k<=j-1;k++)
            {
                __int128 temp = (2*dp[s][i][k]+dp[s][k+1][j]>dp[s][i][k]+2*dp[s][k+1][j])?2*dp[s][i][k]+dp[s][k+1][j]:dp[s][i][k]+2*dp[s][k+1][j];
                dp[s][i][j]=(dp[s][i][j]>temp)?dp[s][i][j]:temp;
            }
        }
    }
    }
    __int128 maxn=0;
    for(int i=1;i<=n;i++)
    {
        maxn+=dp[i][1][m];
    }
    write(2*maxn);
    system("pause");
    return 0;
}
//这题真是得意之作了：题设要你正着取，但这样区间之间毫无联系！倒着去操作立马知道转移方程
