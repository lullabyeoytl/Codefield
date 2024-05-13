#include <bits/stdc++.h>
using namespace std;
long long f[250000001];
long long p[250000001];
long long b[500005];


int main()
{
    int n,m;
    long long k;
    scanf("%d%d%lld",&n,&m,&k);
    for(int i = 1;i<=m;i++)
    f[i] = i;
    for(int s = 2;s<=n;s++)
    {
        for(int j =1;j<=m;j++)
        {
            b[j] = s*m;
        }
        merge(f+1, f+(s-1)*m+1, b+1, b+m+1, p+1);
        for(int d= 1;d<=s*m;d++)
        f[d]=p[d];
    } 
    printf("%d",f[k]);
    return 0;   

}
/*
 bool operator<(const person &t)const{
        if (t.s != s) return s > t.s;
        return idx < t.idx;
    }  //operator 重载运算符定义记住此模板！
*/