#include <cstdio>
#include <cstring>
 /*
 while(lo+1<hi){//二分查找模板 
		mid=(lo+hi)/2;
		if(check(mid))lo=mid;
		else hi=mid;
 */
int n, m;
long long pres[1006][1006];//p[n][m];
int mid;
long long r[1000006]; long long  d[1000006];long long s[1000006];int t[1000006];
int check(int k)
{
    int ra=0;
    for(int i = 1; i<=n; i++)
    {
        if(pres[i][k] <= r[i])
        ra+=1;
        else
        break;
    }
    if(ra==n)
    return 1;
    else
    return 0;
}
int main()
{
    memset(pres , 0, sizeof(pres));
    scanf("%d%d", &n, &m);
    for(int i =1 ; i<= n; i++)
    {
        scanf("%lld", &r[i]);
    }
    for(int j =1; j<=m ; j++ )
    {
        scanf("%lld%lld%lld", &d[j], &s[j], &t[j]);
    }
    //前缀和预备工作
    int rad=0;
    for(int i =1; i<= n; i++)
    {
        for(int j=1; j<=m ;j++)
        {
            if(i>= s[j] && i<= t[j] )
            {
                pres[i][j] = d[j]+pres[i][j-1];
            }
        }
        if(pres[i][m] <= r[i] )
        rad +=1;
        else
        break;
    }
    if(rad == n)
   {
     printf("0");
   }
    //开始二分查找
    else
    {
        int lo = 1; int hi = m;
         while(lo+1<hi)
         {//二分查找模板 
		mid=(lo+hi)/2;
		if(check(mid))
        hi=mid;
		else lo=mid;
        }
    
    printf("-1\n");
    printf("%d\n", hi-1);
    }
    return 0;
   
}