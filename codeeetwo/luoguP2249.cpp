#include <cstdio>
using namespace std;
long int a[100005];long int q;int res[100005];
int n, m,mid;
int check(long int qs)
{
     int lo = 1; int hi = n;
        while(lo < hi)
        {
            int mid = lo + (hi-lo)/2;
           if(a[mid] >= qs)
           {
            hi =mid;
           }
           else
           lo = mid +1;  
        }                            //这个二分模板会更好，因为lo = hi 无需特判；>= 保证第一个， <= 自然最后一个
    if( a[lo] == qs)
    return lo;
    else
    return -1;
}
int main()
{
    scanf("%d %d", &n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%ld", &a[i]);
    }
    for(int i =1; i<= m; i++)
    {
        scanf("%ld", &q);
        res[i] = check(q);
    }
     for(int i =1; i<= m; i++)
     printf("%d ", res[i]);

    return 0;
}