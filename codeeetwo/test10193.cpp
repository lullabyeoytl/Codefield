/*
#include <bits/stdc++.h>
using namespace std;
int zhouqi[202];
int p;
int fibr[10000000];
int fib(int p,int t )
{
    if(t==0)return 0;
    if(t<=2)
    return 1;
    else
    {
        if(fibr[t]!=0)return fibr[t];
        else
        return fibr[t] = (fib(p,t-1) +fib(p,t-2))%p;
    }
}
int zhouq(int q)
{
    int i;
    for( i= 2; ;i++)
    {
        if(fib(q,i)==1&&fib(q,i+1)==1)
       break;
        else continue;
    } 
    return i;
}
int main()
{
    int n;
    scanf("%d%d",&n,&p);
    int T=zhouq(p);
    for(int i =1;i<=n;i++)
    {
        int x0,y0;
        scanf("%d%d",&x0,&y0);
        int cheq=0;
        for(int j = 1;j<=2*T-1;j++)
        {
            if(j%4==1)
            {
                int x = (fib(p,j)*x0+fib(p,j+1)*y0)%p;
                int y = (fib(p,j-1)*x0+fib(p,j)*y0)%p;
                if(x==0)
                {
                    printf("1\n");
                    cheq = 1;
                    break;
                }
                if(y==0)
                {
                    printf("2\n");
                    cheq = 1;
                    break;
                }
            }
            if(j%4==2)
            {
               int x= (fib(p,j-1)*x0+fib(p,j)*y0)%p;
                int y = (fib(p,j)*x0+fib(p,j+1)*y0)%p;
                  if(x==0)
                {
                    printf("1\n");
                    cheq = 1;
                    break;
                }
                if(y==0)
                {
                    printf("2\n");
                    cheq = 1;
                    break;
                }
            }
            if(j%4==3)
            {
                int x = (fib(p,j)*x0+fib(p,j+1)*y0)%p;
                int y = (fib(p,j-1)*x0+fib(p,j)*y0)%p;
                  if(x==0)
                {
                    printf("1\n");
                    cheq = 1;
                    break;
                }
                if(y==0)
                {
                    printf("2\n");
                    cheq = 1;
                    break;
                }
            }
            if(j%4==0)
            {
                int x = (fib(p,j-1)*x0+fib(p,j)*y0)%p;
                int y = (fib(p,j)*x0+fib(p,j+1)*y0)%p;
                  if(x==0)
                {
                    printf("1\n");
                    cheq = 1;
                    break;
                }
                if(y==0)
                {
                    printf("2\n");
                    cheq = 1;
                    break;
                }
            }

        }
        if(cheq==0)printf("error\n");
        
    }


    return 0;
}
*/

#include <cstdio>
using namespace std;
int t,x,y,mod;
short bk[10010][10010]; 
int rem(int x,int y)
{
	if(bk[x][y] == -1) return -1;
	if(bk[x][y]) return bk[x][y];
	bk[x][y]=-1;
	if(!x) return bk[x][y]=1;
	if(!y) return bk[x][y]=2;
	int num=(x+y)%mod;
    return bk[x][y]=rem(num,(num%mod+y)%mod);
}
int main()
{
	scanf("%d %d",&t,&mod);
	for(int i=0;i<t;i++) 
	{
		scanf("%d %d",&x,&y); 
		int ans=rem(x,y);
		if(ans == -1) printf("error\n");
		else if(ans == 1) printf("1\n");
		else printf("2\n");
	}
	return 0;
}


