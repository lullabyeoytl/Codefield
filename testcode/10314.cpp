#include<iostream>
using namespace std;
int main()
{
   int n,count=1,i;
   cin>>n;
   int a[100001],b[100001];
   a[n]=2000000001;
   for(i=0;i<n;i++)
    cin>>a[i]>>b[i];
   for(i=1;i<n;i++)
   if(a[i]-a[i-1]>b[i])
   ++count;
   else if(a[i+1]-a[i]>b[i])
   a[i]+=b[i],++count;
   cout<<count;
   return 0;
}