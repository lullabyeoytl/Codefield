#include <iostream>
#include <queue>
template<typename T>
inline T read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int main(){
    int t = read<int>();
    while (t--){
        int n = read<int>();
        std::queue <long long> q;
        for(int i=0;i<n;i++){
            int x = read<long long>();
            q.push(x);
            while(q.front()<q.size()){
                q.pop();
            }
            std::cout<<q.size()<<' ';
        }
        std::cout<<std::endl;
    }
}