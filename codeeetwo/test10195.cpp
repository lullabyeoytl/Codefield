#include <bits/stdc++.h>
using namespace std;
int input[7];
int sta[7]={0,1,1,2,2,2,8};
int main()
{
    for(int i=1;i<=6;i++)
    {
        scanf("%d",&input[i]);
    }
    for(int i=1;i<=6;i++)
    {
        printf("%d ",sta[i]-input[i]);
    }
    


    return 0;
}