#include <bits/stdc++.h>
#pragma GCC optimize(2)//手动开o2优化
int N,Q;
int a[100005];int li[100005] ; int ri[100005];
int lmax[100005];int ans[100005];
int main()
 {
    scanf("%d%d", &N, &Q);
    for(int i = 1; i<= N ; i++)
    {
        scanf("%d", &a[i]);
    }
    // 预处理
    lmax[1] = 0;
    for(int i=2; i<=N; i++)
    { 
        int j;
        for(j = i-1; j>=lmax[i-1]+1; )
        {
            if(a[j] == a[i])
            break;
            else
            j -= 1;
        }
        lmax[i] = j ;

    }
    //类似前缀和的一种“记忆化”思想，使每次查询时间复杂度为o（1）；

    for(int i = 1; i<=Q; i++)
    {
        scanf("%d%d", &li[i], &ri[i]);
        if(lmax[ri[i]] >= li[i])
        ans[i] = 0;
        else
        ans[i] = 1;
    }
     
     for(int i = 1; i<= Q; i++)
     {
        if(ans[i]==0)
        printf("No\n");
        if(ans[i] == 1)
        printf("Yes\n");
     }
    return 0;
    
 }
//要开o2优化；