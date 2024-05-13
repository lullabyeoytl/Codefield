#include<iostream>
#include<cstdio>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    priority_queue<ll,vector<ll>,greater<ll> > q;
    int n;
    cin>>n;
    ll t;
    for(int i=1;i<=n;i++){
        cin>>t;
        q.push(t);
    }
    ll ans=0,tmp=0,a=0,b=0;	
    while(q.size()>1){
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        tmp=a+b;
        ans+=tmp;
        q.push(tmp);
    }
    cout<<ans<<endl;
    return 0;
}
