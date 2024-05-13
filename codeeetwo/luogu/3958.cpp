#include <bits/stdc++.h>
using namespace std;
struct MESS{
    int xi;
    int yi;
    int zi;
    int id;
    int faid;
  bool  operator < (const MESS b)
    {
        return this->zi<b.zi;
    }
}mess[1003];//fa[x]指id为x的父节点信息
int distcheck(struct MESS A,struct MESS B,int r )
{
    if((A.xi-B.xi)*(A.xi-B.xi)+(A.yi-B.yi)*(A.yi-B.yi)+(A.zi-B.zi)*(A.zi-B.zi)<=4*r*r)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int get(int x)//x是结构体的id
{
   if(mess[x].faid==mess[x].id)return mess[x].faid;
   else
   return mess[x].faid=get(mess[x].faid);

}
void merge(int x,int y)
{
    mess[get(x)].faid=get(y);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int n,h,r;
        scanf("%d%d%d",&n,&h,&r);
        for(int cnt=1;cnt<=n;cnt++)
        {
            scanf("%d%d%d",&mess[cnt].xi,&mess[cnt].yi,&mess[cnt].zi);
        }
        sort(mess+1,mess+n+1);
         for(int cnt=1;cnt<=n;cnt++)
        {
            mess[cnt].id=cnt;
            mess[cnt].faid=cnt;
        }
        for(int k=2;k<=n;k++)
        {
            for(int l=k-1;l>=1;l--)
            {
                if(distcheck(mess[k],mess[l],r))
                {
                    merge(k,l);

                }
            }
        }

        int lo1=1;int hi1=n;
        while(lo1<hi1)
        {
            int mid=(lo1+hi1)/2;
            if(mess[mid].zi<r)lo1=mid;
            else hi1=mid-1;
        }
        int lo2=1,hi2=n;
        while(lo2<hi2)
        {
            int mid=(lo2+hi2)/2;
            if(mess[mid].zi>n-r)hi2=mid;
            else lo2=mid+1;
        }
        int check=0;
        for(int li=1;li<=lo1;li++)
        {
            for(int ri=lo2;ri<=n;ri++)
            {
                if(get(li)==get(ri))
                {
                    check=1;
                    printf("Yes\n");
                    break;
                }

            }
            if(check)break;
        }
        if(!check)printf("No\n");

    }
    system("pause");
    return 0;
} 
