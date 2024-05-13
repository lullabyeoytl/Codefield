#include <bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
    long long x;
    scanf("%lld",&x);
    if(x%62==0)
    {
        printf("Yes");
    }
    else
    {
        long long s=x;int i = 0;
        while(s/10>0)
        {
           
           a[i] = s%10;
           i+=1;
           s/=10;
        }
        a[i]=s;//0daoi 
        int cnt = 0;
        for(int j =0;j<=i-1;j++)
        {
            if(a[j]==2&&a[j+1]==6)
            {
                printf("Yes");
                cnt = 1;
                break;
            }
            
        }
        if(cnt==0)
        printf("No");
    }
    return 0;
}