#include <bits/stdc++.h>
using namespace std;
char S[1001],M[1001];
int main()
{
    priority_queue <int> qs1,qs2;
    priority_queue <int> qm1,qm2;
    int n;
    scanf("%d",&n);
    scanf("%s",S);
    scanf("%s",M);
    for(int i=0;i<n;i++)
    {
       int s=S[i]-48;
       int m=M[i]-48;
       qs1.push(s);qm1.push(m);
       qs2.push(-s);qm2.push(m);
    }
    while(qs1.size()&&qm1.size())
    {
        int tom=qm1.top();
        int tos=qs1.top();
        if(tom>=tos)
        {
            qm1.pop();
            qs1.pop();
        }
        else
        {
            qs1.pop();
        }
    }
    while(qs2.size())
    {
         int tom=qm2.top();
        int tos=-qs2.top();
        if(tom>tos)
        {
            qm2.pop();
            qs2.pop();
        }
        else 
        {
            qs2.pop();
        }
    }
    printf("%d\n%d",qm1.size(),n-qm2.size());
    return 0;

}