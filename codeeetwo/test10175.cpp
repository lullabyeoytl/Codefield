#include <bits/stdc++.h>
using namespace std;
int a[100005];
int s[100005];
int mid;
int main()
{
    int n;s[0]=0;
    scanf("%d",&n);
    int sum = 0;
    for(int i =1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        s[i] = a[i]+s[i-1];
    }
    sort(s+1,s+n+1);
    if(s[1]>=0)printf("1");
    else
    printf("%d",-s[1]+1);
    return 0;
    
}