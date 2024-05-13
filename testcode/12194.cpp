#include<iostream>
#include<string>
using namespace std;
int n,m,f[1001],eny[1001]; 
int find(int x)         
{
    while(f[x]!=x) x=f[x]; 
    return x;
}
void emerge(int x,int y)    
{
    x=find(x);y=find(y);  
    if(x==y) return;
    f[y]=x;
    return;
}
int main()
{
     cin>>n>>m;
     for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int p,q;
        char c;
        cin>>c>>p>>q;
        if(c=='F') emerge(p,q);  
        else {
                if(eny[p]==0) eny[p]=find(q);
              else emerge(q,eny[p]);
              if(eny[q]==0) eny[q]=find(p);
              else emerge(p,eny[q]);
            } 
    }
    int count[1001]={0};
    for(int i=1;i<=n;i++)
        count[find(i)]++;
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(count[i]) cnt++;  
    cout<<cnt;
 } 