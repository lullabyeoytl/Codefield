#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
int ans[MAXN],col[MAXN],lim[MAXN];
map<int,int>c[MAXN],t[MAXN];
vector<int>g[MAXN],Q[MAXN];
 
void dfs(int v,int p){
    c[v][col[v]]++;
    t[v][1]++;
    for(int u:g[v])
    {
        if(u==p)continue;
        dfs(u,v);
        if(c[v].size()<c[u].size())
        c[v].swap(c[u]),t[v].swap(t[u]);
        for(auto x:c[u]){
            int k=c[v][x.F];
            c[v][x.F]+=x.S;
            for(int i=1;i<=x.S;i++)
            t[v][k+i]+=1;
            
        }
    }
    for(int q:Q[v])
    ans[q]=t[v][lim[q]];
}
 
int main(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    cin>>col[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        
    }
    for(int i=0;i<q;i++){
        int v;cin>>v>>lim[i];
        Q[v].push_back(i);
        
    }
    dfs(1,0);
    for(int i=0;i<q;i++)
    cout<<ans[i]<<'\n';
}