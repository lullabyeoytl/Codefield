#include <cstdio>
#include<algorithm>
using namespace std;
int n ;long int c; int res =0;
long int a[200005];
bool cmp(int a, int b)
{
    return a<=b ; 
}

int check(int t)
{
     int lo = 1; int hi = t-1;
        while(lo < hi)
        {
            int mid = lo + (hi-lo)/2;
           if(a[mid] >=a[t]- c)
           {
            hi =mid;
           }
           else
           lo = mid +1;  
        }   //lo是第一个满足的下标
    if( a[lo] == a[t]-c)
    {
        int s=0;
        while (a[lo+s] == a[lo])
        s++;
        return s;
    }
    else
    return 0;             
}
int main()
{
    scanf("%d %ld", &n, &c);
    for(int i = 1; i<= n; i++)
    {
        scanf("%ld", &a[i]);
    }
    sort(a+1, a+n+1 , cmp);
    for(int i = n; i>=1; i-- )
    {
        if(a[i]<=c)
        break;
        else
        {
           res += check(i);
        }
    }
    printf("%d", res);
    return 0;
}