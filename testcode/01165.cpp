#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int dp[1001];
int main(){
    int t=read();
    for(int o=1;o<=t;o++){
        int sum=0;
        memset(dp,0,sizeof(dp));
        int n=read(),k=read();
        for(int j=1;j<=n;j++){
            int x=read();
            sum+=x/k;
            dp[x%k]+=1;
        }
        for(int i=1;i<k-i;i++){
            sum+=min(dp[i],dp[k-i]);
            dp[i]-=min(dp[i],dp[k-i]);
            dp[k-i]-=min(dp[i],dp[k-i]);;
        }
        if(k%2==0){
            sum+=dp[k/2]/2;
            dp[k/2]%=2;
        }
        int d_sum=0;
        if(dp[1]==0)d_sum+=dp[k-1];
        for(int i=2;i<=(k-1)/2;i++){
                sum+=min(dp[i],d_sum);
              d_sum-=min(dp[i],d_sum);
              d_sum+=dp[k-i];
            }
        sum+=d_sum/2;
        printf("%d\n",sum);
    }
}