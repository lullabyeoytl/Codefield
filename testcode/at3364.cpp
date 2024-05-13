#include <bits/stdc++.h>
using namespace std;
int n;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[200005];
int l_find(int mid,int pos,int i){
    if(pos>n){
        return 0;
    }
    if(i==1){
        if(a[pos]>=i) return l_find(mid,pos+1,i+1);
        else return l_find(mid,pos+1,i);
    }
    if(i==mid){
        if(a[pos]>=mid)
        return pos;
        else
        return l_find(mid,pos-mid+2,1);
    }
    else{
        if(a[pos]>=i) return l_find(mid,pos+1,i+1);
        else return l_find(mid,pos-i+2,1);
    }
}
int r_find(int pos,int i){
    if(pos>n){
        return 0;
    }
    else if(i==0)
    return pos;
    else if(i==1){
        if(a[pos]>=i)return pos;
        else return r_find(pos+1,1);
    }
    else {
        if(a[pos]>=i) return r_find(pos+1,i-1);
        else return r_find(pos+1,i);
    }
}
int chek(int mid){
    if(l_find(mid,1,1)==0)return 0;
    else
    {
        if(r_find(l_find(mid,1,1)+1,mid-1)!=0)
        return 1;
        else
        return 0;
    }
}
int main(){
    n=read();
    if(n==1||n==2)
    {
        printf("1");
        return 0;
    }
    int max=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]>max)max=a[i];
    }
    int k=(n+1)/2;
    int hi=min(k,max);int lo=1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(!chek(mid))hi=mid; 
        else lo=mid+1;
    }
    if(chek(lo+1))
    {
        printf("%d",lo+1);
        return 0;
    }
    else if(chek(lo)){
        printf("%d",lo);
        return 0;
    }
    else
    printf("%d",lo-1);
    return 0;
}