#include <bits/stdc++.h>
using namespace std;
char a[260];
int main()
{
    stack <char> sta;
    gets(a);
    int check =0;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='(')
        {
            sta.push(a[i]);
        }
        else if(a[i]==')')
        {
            if(sta.empty())
            {
                printf("NO");
                check=1;
                break;
            }
            else
            sta.pop();
        }
        else
        continue;
    }
    if(sta.empty()&&!check)
    {
        printf("YES");
    }
    if(!sta.empty())
    {
        printf("NO");
    }
    system("pause");
    return 0;
}