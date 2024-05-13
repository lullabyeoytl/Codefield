/*
#include <bits/stdc++.h>

int n;
char tar[10] = {'y','i','z','h','o','n','g'};
int dx[10] = {0,1,1,0,-1,-1,-1,0,1};
int dy[10] = {0,0,1,1,1,0,-1,-1,-1};
char a[101][101];
int dp[101][101];
int sp[101][101];
void dfs(int x,int y,int t, int i)
{
    if(t==7)
    {
        for(int j=6;j>=0;j--)
        {
            sp[x-j*dx[i]][y-j*dy[i]] = 1;
        }
        return ;
    }
    else
    {
        x+=dx[i];y+=dy[i];
        if(x>=1&&x<=n&&y>=1&&y<=n&&a[x][y]==tar[t])
        {
            dp[x][y]=1;
            dfs(x,y,t+1,i);
            dp[x][y]=0;//回溯 
        }
        
    }
}

int main()
{
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    memset(sp,0,sizeof(sp));
    for(int i = 1; i<=n;i++)
    {
        getchar();
        for(int j =1;j<=n;j++)
        scanf("%c",&a[i][j]);
    }
    for(int i  =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            if(a[i][j]=='y')
            {
                for(int k = 1;k<=8;k++)
                {
                    dfs(i,j,1,k);
                }
            }
        }
    }
    for(int i  =1;i<=n;i++)
    {
        for(int j  =1;j<=n;j++)
        {
            if(sp[i][j]!=0)
            printf("%c",a[i][j]);
            else
            cout<<"*";
        }
        printf("\n");
    }
    return 0;

}
*/
#include<iostream>
using namespace std;
int c[10000][2],d=0,x[9]={0,1,0,1,-1,0,-1,1,-1};
int                 y[9]={0,0,1,1,0,-1,-1,-1,1};
char a[103][103],b,k[9]=" yizhong";
bool s[102][102];
bool f(int i,int j,int m,int n,int next){
    if(next>=8){
        s[i][j]=1;
        return 1;
    }
    if(a[i+m][j+n]==k[next])
        if(f(i+m,j+n,m,n,next+1)){
        	s[i][j]=1;
        	return 1;
        }
    return 0;
}
int main(){
    int n,i,j,o;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>b;
            if(b=='y'){
                c[++d][0]=i;
                c[d][1]=j;
            }
            a[i][j]=b;
        }
    }
    while(d){
        i=c[d][0];
        j=c[d][1];
        for(o=1;o<=8;o++){
           if(a[i+x[o]][j+y[o]]=='i')
              if(f(i+x[o],j+y[o],x[o],y[o],3))
                 s[i][j]=1;
        }
        d--;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(s[i][j])cout<<a[i][j];
            else cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}