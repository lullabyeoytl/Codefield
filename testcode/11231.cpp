#include <bits/stdc++.h>
using namespace std;
int dp[301];
char s[301],si[501][301];
int main()
{
    int n,l;
    bool xcheck;
    scanf("%s%d",s,&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",si[i]);
    }
    l=strlen(s);
    for (int i=0;i<l;i++)
    {
        for (int j=1;j<=n;j++)
        {
            int len=strlen(si[j]);
            if (l-i<len) 
            continue;
            xcheck=true;
            for (int k=0;k<len;k++)
            {
                if (s[k+i]!=si[j][k])
                {
                    xcheck=false;
                    break;
                }
            }
            if (xcheck){
                for (int k=i+len-1;k<l;k++)
                {
                    if (i==0) 
                    dp[k]=max(dp[k],1);
                    else dp[k]=max(dp[k],dp[i-1]+1);
                }
            }
        }
    }
    printf("%d",dp[l-1]);
    system("pause");
    return 0;
}