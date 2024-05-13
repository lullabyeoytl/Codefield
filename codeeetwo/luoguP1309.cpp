/*
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int w[100004]; int l[100004];//win lose 二分后归并；
struct player
{
    int id , point , power;
}p[200008]; 



int cmp(player a , player b)
   {
      if(a.point != b.point)
      return a.point > b.point;
      return a.id < b.id;

   }
   

 
int main (void)
{
    int N, R , Q;
    scanf("%d%d%d", &N ,&R, &Q);
    for(int i = 1; i<= 2*N ; i++)
    {
        scanf("%d" , &p[i].point);
        p[i].id = i;
    }
    for(int i = 1; i<= 2*N ; i++)
    scanf("%d" , &p[i].power);  //scan work
    

   
   sort (p , p+2*N, cmp);

   


    for(int i =1 ; i<= R; i++)
    {
        for(int j= 1; j<=N;j++ )
        {
            if(p[2*j-1].power > p[2*j]. power)
            {
                 p[2*j-1].point++;
                 w[j]= p[2*j-1].point;//错误写法！p是一个结构体而w是数组，正确写法应把w和l都设为结构体然后赋值，这是写成w[j]=p[2*j-1]
                 l[j]=p[2*j]. point;
            }
            else
            {
                 p[2*j].point++;
                 w[j]= p[2*j].point;
                 l[j]=p[2*j-1].point;
            }
        }
        merge(l+1, l+N+1, w+1, w+N+1, p+1);
    }
    printf("%d", p[Q].id);
    return 0;
}
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N= 2e5+7;
int n,r,q;
struct person{
    int s, idx, w;

	// 运算符重载，双关键字排序
    bool operator<(const person &t)const{
        if (t.s != s) return s > t.s;
        return idx < t.idx;
    }  //operator 重载运算符定义记住此模板！
    

	// debug
    void print(){
        printf("people: idx(%d), s(%d), w(%d)\n", idx, s, w);
    }
};
person p[N], loser[N], winer[N];

int main(){
    //freopen("in.txt","r",stdin);

    cin >> n >> r >> q;
    for(int i = 1; i <= n*2; i++) cin >> p[i].s;
    for(int i = 1; i <= n*2; i++) cin >> p[i].w;
    for(int i = 1; i <= n*2; i++) p[i].idx = i;
    sort(p+1, p+1+n*2 , cmp);

    for(;r--;){ // 然后就是给双指针
        for(int i=1;i<=n;i++){
            if (p[2*i-1].w<p[2*i].w){
                p[2*i].s++;
                loser[i]=p[2*i-1];
                winer[i]=p[2*i];
            }else{
                p[2*i-1].s++;
                loser[i]=p[2*i];
                winer[i]=p[2*i-1];
            }
            
        }
        merge(loser+1, loser+n+1, winer+1, winer+n+1, p+1);
    }
    cout << p[q].idx;
    return 0;
}

