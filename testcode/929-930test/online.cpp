#include <iostream>
#include <vector>
#include <cstring>

const int MOD = 1000000007;

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

inline long long lread()
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
int main() {
    int n=read();
    long long num[100001];
    long long max_num = 0;
    for (int i = 0; i < n; i++) {
        num[i]=lread();
        if (num[i] > max_num) {
            max_num = num[i];
        }
    }
    long long* dp = (long long*)malloc(sizeof(long long)*(max_num+1)); 
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= max_num; i++) {
        dp[i] = ((3*dp[i-1]-dp[i-2])%MOD+MOD)%MOD;
    }
    for(int i=0;i<n;i++){
        printf("%lld\n",dp[num[i]]);
    }
    free(dp);
    return 0;
}