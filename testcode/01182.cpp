#include <bits/stdc++.h>
using namespace std;
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
int check(int a[],int b[]){
    if(a[1]<2){
        if(a[0]<6)return 1;
        else return 0;
    }
    else{
        if(b[1]>=4)return 0;
        else{
            return 1;
        }
    }
}
int plu(int * a,int * b){
    int k= *a;int t = *b;
    if(t==59){
        *b=0;
        if(k==23)*a=0;
        else (*a)++;
    }
    else{
        (*b)+=1;
    }
    return 0;
}
int main(){
    int H=read(),M=read();
    int a[2]={H%10,H/10};
    int b[2]={M%10,M/10};
    while(!check(a,b)){
        plu(&H,&M);
        a[0]=H%10,a[1]=H/10;
        b[0]=M%10,b[1]=M/10;
    }
    printf("%d %d",H,M);
    
}