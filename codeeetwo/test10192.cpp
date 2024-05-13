#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long p[101];
long long mi[100][100];//按3的幂次分类
int ki[100];//即每个幂次多少数
int main()
{
   
    int n;
    scanf("%d",&n);
    memset(ki,0,sizeof(ki));
    for(int i =1;i<=n;i++)
    {
        scanf("%lld",&p[i]);
        int s=0;
        long long temp = p[i];
        while(temp%3==0)
        {
            temp/=3;
            s++;
        }
        ki[s] +=1;
        mi[s][ki[s]] = p[i];//按三的幂次分类，ki[s]为幂次为s的p[i]个数
        
    }
    int lo=0;
    while(ki[lo]==0)lo++;//lo最低幂次
    int gdg = 0;
    for(int i =lo; ki[i]!=0;i++)
    {
        sort(*(mi + i)+1, *(mi +i) + (ki[i]+1));
        gdg++;
    }
    for(int i =gdg+lo-1;i>=lo;i--)
    {
        for(int j = 1;j<=ki[i];j++)
        printf("%lld ", mi[i][j]);
    }
    return 0;
}