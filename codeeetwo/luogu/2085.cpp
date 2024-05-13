#include <bits/stdc++.h>
using namespace std;
struct Num{
    int id;
    int arr;
    int num;
    bool operator <(const Num b)
    {
        return this->num < b.num;
    }
}  Nub[10005][10005];
bool operator >(Num a, Num b) {
    return a.num > b.num;
    }
priority_queue<struct Num,vector<struct Num>,greater<struct Num> >q;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        for(int j=1;j<=m;j++)
        {
            Nub[i][j].arr=i;
            Nub[i][j].id=j;
            Nub[i][j].num=a*j*j+b*j+c;
        }
        q.push(Nub[i][1]);
    }
    for(int i=1;i<=m;i++)
    {
        struct Num to=q.top();
        printf("%d ",to.num);
        q.pop();
        q.push(Nub[to.arr][to.id+1]);
    }
    system("pause");
    return 0;
}
