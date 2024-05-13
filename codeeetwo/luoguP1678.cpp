#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std; 
int smallest(int x, int y, int z){
    return std::min({x, y, z});
}                //用stl找min记得加这个！
int m,n;
int us[100005]; int ss[100005];
int res=0;
bool amp(int a, int b)
{
    return a<b;
}
int check(int t)
{
     int lo = 1; int hi = m;
        while(lo < hi)
        {
            int mid = lo + (hi-lo)/2;
           if(us[mid] >=ss[t])
           {
            hi =mid;
           }
           else
           lo = mid +1;  
        }   //lo是第一个满足的下标
        int ans;
       if(us[1] >= ss[t]) // 极端边界情形不要忘了特判！
        ans = us[1] - ss[t];
        else if (us[m] <= ss[t])
        ans = ss[t] - us[m];
       else
       {
         ans= smallest( abs(ss[t]-us[lo]), abs(ss[t]-us[lo-1]), abs(ss[t]-us[lo+1]));   
        }
    return ans;

}
int main()
{
    memset(us,-1,sizeof(us));
    memset(ss,-1,sizeof(ss));
    scanf("%d%d", &m, &n);
    for(int i = 1; i<= m; i++)
    {
        scanf("%d" , &us[i]);
    }
    sort(us+1, us+m+1, amp);
    for(int i =1; i<= n; i++ )
    {
        scanf("%d", &ss[i]);
        res+=check(i);
    }
    printf("%d", res);
    return 0;
}