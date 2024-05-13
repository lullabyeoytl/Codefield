#include <bits/stdc++.h>
using namespace std;

int a1[100005];
int a2[100005];
int se1[3000000];
int main()
{
    priority_queue <int> pr1, pr2;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int nsum;
        scanf("%d",&nsum);
        for(int j=1;j<=nsum;j++)
        {
            scanf("%d",&a1[j]);
            pr1.push(a1[j]);
        }
        for(int j=1;j<=nsum;j++)
        {
            scanf("%d",&a2[j]);
            pr2.push(a2[j]);
        }
        int sum1=0,sum2=0;
        for(int k=1;k<=n-n/4;k++)
        {
            se1[k]= pr1.top();
            pr1.pop();
            sum1+=se1[k];
        }
        for(int k=1;k<=n-n/4;k++)
        {
            int s= pr2.top();
            pr2.pop();
            sum2+=s;
        }
        if(sum1>sum2)
        {
            printf("0\n");
        }
        else
        {
            int s=0;int temp=0;
            while(sum1<=sum2)
            {
                
                pr2.push(0);
                s+=1;
                if(n%4)
                {
                    sum1+=100;
                    sum2+= pr2.top();
                    pr2.pop();
                }
                else
                {
                    sum1+=100;
                   if(n-n/4-temp>0) sum1 -= se1[n-n/4-temp];
                   else
                   {
                       sum1-=100; 
                   }
                    temp++; 
                }
            }
            printf("%d\n",s-1);
        }
        while(!pr1.empty())
        {
            pr1.pop();
        }
        while(!pr2.empty())
        {
            pr2.pop();
        }
        continue;
        
    }
    system("pause");
    return 0;
}