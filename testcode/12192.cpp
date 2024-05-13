#include<bits/stdc++.h>
using namespace std;
int f[1001];
int find(int x){
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}
long long dis(long long x,long long y,long long z,long long x1,long long y1,long long z1){
    return (x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1);
}
long long x[100001],y[100001],z[100001];
int f1[100001],f2[100001];
int main(){
    int t;
    scanf("%d",&t);
    int n,h; 
    long long r;
    for (int i=1;i<=t;i++){
        scanf("%d%d%lld",&n,&h,&r);
        int tot1=0;
        int tot2=0;
        for (int j=1;j<=n;j++){
          f[j]=j;  
         }
        for (int j=1;j<=n;j++){
            scanf("%lld%lld%lld",&x[j],&y[j],&z[j]);
            if (z[j]+r>=h){
                tot1++;
                f1[tot1]=j;
            }
            if (z[j]-r<=0){
                tot2++;
                f2[tot2]=j;
            }
            for (int k=1;k<=j;k++){
            	if ((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k])>4*r*r) continue;
                if (dis(x[j],y[j],z[j],x[k],y[k],z[k])<=4*r*r){
                    int a1=find(j);
                    int a2=find(k);
                    if (a1!=a2) f[a1]=a2;
                }
            }
        }
        int s=0;
        
        for (int j=1;j<=tot1;j++){
            for (int k=1;k<=tot2;k++){
                if (find(f1[j])==find(f2[k])){
                    s=1; 
                    break;
                }
            }
            if (s==1) break;
        }
        if (s==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
} 