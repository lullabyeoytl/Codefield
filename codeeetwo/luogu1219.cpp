#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000],c[1000],d[1000],n,res;
void print()
{
    int i;res++;
    if(res<=3)
    {
        for(i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
}
    int dfs(int i){
        int j;
        for(j=1;j<=n;j++)
            if(b[j]==0&&c[i+j]==0&&d[i-j+n]==0){//判断
                a[i]=j;//写进去（第i行第j个） 
                b[j]=1;//占行 
                c[i+j]=1; d[i-j+n]=1;//占对角线 
                if(i==n)print();//满足条件输出 
                else dfs(i+1);//继续推 
                b[j]=0;c[i+j]=0;d[i-j+n]=0;//回溯
            }
        return 0;
    }
     int main(){
        cin>>n;
        dfs(1); 
        cout<<res<<endl;
        return 0;
}