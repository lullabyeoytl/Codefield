#include<bits/stdc++.h>
using namespace std;
char str[1025];
void build(int x,int y)
{
    if(y>x)
    {
        build(x,(x+y)/2);
        build((x+y+1)/2,y);
    }
    int b=1,i=1;
    for(int j=0;j<=y-x;j++)
    {
        if(str[x+j]=='1'){
             b=0;
        }
        else i=0;
    }
    if(b)printf("B");
    else if(i) printf("I");
    else printf("F");
}
int main()
{
    int n;
    scanf("%d%s",&n,str);
    build(0,pow(2,n)-1);
    system("pause");
    return 0;
} 