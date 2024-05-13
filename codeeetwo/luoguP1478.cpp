#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct apple
{
    int x;
    int y;
}u[5010], u1[5010];

bool cmp(apple a, apple b){
	
		return a.y < b.y;
}

int main(void)
{
    int n ,s,a,b;
    scanf("%d%d", &n ,&s);
    scanf("%d%d", &a,&b);
   
    for( int t =1; t<= n ;t++)
   {
       scanf("%d %d" , &u[t].x , &u[t].y);
    }
    int i1=0;
    for(int i =1; i<=n; i++ )
    {
        if(u[i].x<=a+b)
        { 
            i1+=1;
          u1[i1].x = u[i].x;
          u1[i1].y = u[i].y;
        }//i1为可摘集个数
        
    }
    //排序
    sort(u1+1 , u1+i1 ,cmp);
    int f =1;
    while(s - u1[f].y >= 0)
    {
        s -= u1[f].y;
        f += 1;
    }
    printf("%d" , f-1);
    return 0;
    
}



