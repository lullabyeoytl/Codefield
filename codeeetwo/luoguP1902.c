//思路，深搜加二分，二分最大值。
/*
二分板子
int lo=1,hi=L+1,mid;
	while(lo+1<hi){//二分查找模板 
		mid=(lo+hi)/2;
		if(check(mid))lo=mid;
		else hi=mid;
	}
*/
#include <string.h>
#include <stdio.h>
int p[1005][1005];
int mark[1005][1005];
int goi[4] = {-1,1,0,0}; int goj[4]={0,0,-1,1};
int n,m;
int check;
int mid;

void dps(int x , int y )
{
    
    for(int a = 0 ; a<=4; a++)
    {
        if(x+goi[a] >= 1 && x+goi[a] <= n && y+goj[a]>=1 &&y+goj[a]<=m && mark[x+goi[a]][y+goj[a]] != 1 && p[x+goi[a]][y+goj[a]] <= mid) // 合理化减枝,此处的合理化要加上二分判断加记忆化
        {
            mark[x+goi[a]][y+goj[a]]= 1;
            dps(x +goi[a], y+goj[a]);
           // mark[x+goi[a]][y+goj[a]]= 0;//如果走不下去了归零，回溯，好像也不需要
            if(check==1)return;
        }
        if(x==n)
       {
        check = 1;
        return ;
       }    //check 走完

    }
} 
//搜索完成即表示小于mid的有一个
 
 int divdcheck()
 {
    check = 0;
    memset (mark , 0 ,sizeof(mark));
    dps (1,1);
    if(check == 1) return 1;
    else return 0;
 }
 //二分板子中的check函数

 int main()
 {
    scanf("%d%d", &n, &m);
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<= m; j++)
        scanf("%d", &p[i][j]);
    }
    int max =-1; int min = 1001;
    for(int i = 2; i<= n-1; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            if(p[i][j] >= max)
            max = p[i][j];
            if(p[i][j] <= min)
            min = p[i][j];
        }
    }
    int lo=min,hi=max;
	while(lo+1<hi){//二分查找模板 
		mid=(lo+hi)/2;
		if(divdcheck())
        hi=mid;
		else lo=mid;
	}
    printf("%d", lo+1);
   return 0;
 }
 




