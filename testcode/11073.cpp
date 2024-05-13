#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,res,dp[1000005];
int main(){
    cin>>a>>b>>c>>d;
    dp[0]=1;
    for(int i=1;i<a;i++)
    {
        for(int j=i*(i+1)/2;j>=i;j--)dp[j]=(dp[j]+dp[j-i])%100000007;
    }
    for(int i=0;i<=a*(a-1)/2;i++)
    {
        if((b+d*a*(a-1)/2-(c+d)*i)%a==0)res=(res+dp[i])%100000007;
    }
    cout<<res;
    return 0;
}
