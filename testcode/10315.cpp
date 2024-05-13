#include <bits/stdc++.h>
using namespace std;
int la,top,cnt,l,ansl,ansr,ans;
int sta[1000101][2];
char a[1000101];
bool vis[1000101];
int main()
{
    scanf("%s",a);
    la=strlen(a);
    for(int i=0;i<la;++i) 
      if((sta[top][0]=='['&&a[i]==']')||(sta[top][0]=='('&&a[i]==')')) 
      vis[sta[top--][1]]=vis[i]=1;
      else sta[++top][0]=a[i],sta[top][1]=i;
    for(int i=0;i<la;++i)
      if(!vis[i]) cnt=0,l=i+1;
      else {
          cnt++;
          if(cnt>ans) ansl=l,ansr=i,ans=cnt;
      }
    for(int i=ansl;i<=ansr;++i) putchar(a[i]);
    return 0;
}