#include <cstdio>
int n,m;
int mid1,mid2;int a[100005];long int s[100005];//s前缀和，看题设必然要用
/*
int divd(int t)
{
    if(t==0)
    {
        int lo2 = t+1; int hi2= n;
    while(lo2<hi2)
    {
        mid2 = (lo2+hi2)/2;
        if(s[mid2] -s[t] >= mid1)
        hi2 = mid2;
        else
        lo2 = mid2+1;
    }
    return 1;
    divd(lo2 + 1);
    
    }
    else if(t>=1 && t<n)
    {
        int lo2 = t+1; int hi2= n;
       while(lo2<hi2)
      {
        mid2 = (lo2+hi2)/2;
        if(s[mid2] -s[t] >= mid1)
        hi2 = mid2;
        else
        lo2 = mid2+1;
      }
        if(lo2 == n)
        {
        return (divd(t)+1);
        }
      else
       {
         return (divd(t)+1) ;
       divd(lo2 + 1);
      }
    }
}
*/

int main()
{
    s[0] = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i<= n; i++)
    {
        scanf("%d", &a[i]);
        if(i == 1)
        s[1] = a[i];
        if(i > 1)
        s[i] = s[i-1] +a[i];
    }
    int lo1 = 1; int hi1 = s[n];
    while (lo1<hi1)
    {
        mid1 = (lo1 +hi1)/2;
        //if(divd(n)<= m)
        int lo2 = 0; int hi2 = n;int cnt =0;
        while(lo2<n)
        {
          /*while (lo2<hi2)
          {
            int mid2 = (lo2 + hi2)/2;
            if(s[mid2] -s[lo2] >= mid1)
            hi2 = mid2;
            else
            lo2 = mid2+1;
          }
           cnt ++;
           */
          for(int i = lo2+1; i<= n ; i++)
          {
            if(s[i]- s[lo2] >= mid1 || i == n)
            {
                lo2 = i;
                cnt += 1;
                break;
            }
            else
            continue;
          }

        }
        if(cnt >= m)
        lo1 = mid1;
        else
        hi1 = mid1-1; 
    }

    printf("%d\n", lo1);
     return 0;
}