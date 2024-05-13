#include <cstdio>
#include <algorithm>
using namespace std;
int a[30004];int res = 0;
int main()
{
    int w;
    scanf("%d",&w);
    int n;
    scanf("%d",&n);
    for(int i =1; i<=n;i++)
    {
        scanf("%d" ,&a[i]);     
    }
    sort(a+1,a+n+1);
    int s=n;
    while(s>0)
    {
        if(s==1)
        {
            s-=1;
            res+=1;
        }
        else if(s==2)
        {
            if(a[2] > w - a[1])
            {
                res+=2;
                s-=2;
            }
            else
            {
                res+=1;
                s-=2;
            }
        }
        else 
       {
        if(w-a[s] < a[1])
        {
            s-=1;
            res +=1;
        }
       else if(w-a[s] >= a[1])
        {
            int lo=1;
            while((a[lo] <= w-a[s])&& lo < s)
            {
                lo+=1;
            }
            if(lo ==s)
            {
                s-=2;
                res++;
            }
            else 
            {
               for(int i = lo-1; i<= s-2; i++)//一定要想清lo的含义！
              {
                a[i] = a[i+1];
              }
               s-=2;
               res++;
            }
        }
       }


    }
    printf("%d",res);
    return 0;

}