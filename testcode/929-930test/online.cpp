
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

struct Matrix{
    long long a[2][2];
}A;

Matrix operator * (const Matrix& a, const Matrix& b) {
    Matrix c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.a[i][j] = (a.a[i][0] * b.a[0][j]%MOD + a.a[i][1] * b.a[1][j]%MOD+MOD) % MOD;
        }
    }
    return c;
}

Matrix fastpow(Matrix a, long long b){
    Matrix res;
    res.a[0][0]=1;
    res.a[0][1]=0;
    res.a[1][0]=0;
    res.a[1][1]=1;
    if(b==1)
        return a;
    while(b>0){
        if(b&1){
            res =res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}
int main() {
    int n=read();
    long long num[100001];
    long long max_num = 0;
    A.a[0][0]=3;
    A.a[0][1]=-1;
    A.a[1][0]=1;
    A.a[1][1]=0;
    for (int i = 0; i < n; i++) {
        num[i]=lread();
        if (num[i] > max_num) {
            max_num = num[i];
        }
        Matrix tmp = fastpow(A,num[i]-1);
        long long ans = (tmp.a[0][0]%MOD);
        printf("%lld\n",ans);
    }
    return 0;
}

/**矩阵快速幂 */