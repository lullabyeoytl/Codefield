/*
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int res[103];
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=1;i<=t;i++)
    {
        string a;
        getline(cin,a);
        int a1 = a.find(" ");//a1+1weidiergekaitou
        int a2 = a.find(" ",a1+1);
        if(a[0]=='y'&&a[a1+1]=='y'&&a[a2+1]=='d'&&a[a2+2]=='i'&&a[a2+3]=='n'&&a[a2+4]=='g'&&a[a2+5]==' '&&a[a2+6]=='z'&&a[a2+7]=='h'&&a[a2+8]=='e'&&a[a2+9]=='n'&&a[a2+10]=='\r'&&a[a2+11]=='\n')
        {
            //printf("Yes");
            res[i]=1;
        }
        else
        {
           // printf("No");
           res[i]=0;
        }
        
    }
    for(int i=1;i<=t;i++)
    {
        if(res[i])printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n;
string a,b,c,d;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c>>d;
		if(a[0]==b[0] && a[0]=='y' && c=="ding" && d=="zhen")
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
    return 0;
}
