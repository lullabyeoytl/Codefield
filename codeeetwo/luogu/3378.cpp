#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > q;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int x;
            scanf("%d",&x);
            q.push(x);
        }
        if(op==2)
        {
            int x=q.top();
            printf("%d\n",x);
        }
        if(op==3)
        {
            q.pop();
        }
    }
    system("pause");
    return 0;
}