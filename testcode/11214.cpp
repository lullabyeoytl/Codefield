#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int pi=1e9+7;
ll w,n,k;

ll ePow(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%pi)
        if(b&1) ans=ans*a%pi;
    return ans;
}

int main()
{
    cin>>w>>n>>k;
    ll inv2=ePow(2,pi-2);
    ll ans=w*ePow(inv2,k)%pi;
    cout<<ans<<endl;
    return 0;
}