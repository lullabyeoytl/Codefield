#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int j=0;
    int pos=0;
    while(a.find(b[j],pos)!= string::npos)
    {
        pos=a.find(b[j],pos)+1;
        j+=1;
    }
    printf("%d",j);
    system("pause");
    return 0;
}