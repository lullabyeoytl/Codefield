#include <iostream>
#include <algorithm>
using namespace std;
int pre[50005];
int n,len,mx=-1;
int first[7],last[7]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>pre[i];
		pre[i]=(pre[i]+pre[i-1])%7; 		
	}
	for(int i=n;i>=1;i--)
		first[pre[i]]=i;  
	
	first[0]=0;
	for(int i=1;i<=n;i++)
		last[pre[i]]=i;
		
	for(int i=0;i<=6;i++)   
	mx=max(last[i]-first[i],mx);
	cout<<mx<<endl;
    return 0;
} 