#include <cstdio>
#include <cstring>
int main (void)
{
    int N;
    scanf("%d" , &N);
    int sum =0 ;
    for(int i=1; ;i++)
    {
        sum+=i; 
        if(sum < N)
        continue;
        else if(sum == N)
        {
            printf("1/%d" ,i);
            break;
        }
       
       else if(sum > N)
        {
            int t = N- ((i-1)*i)/2;
            printf("%d/%d",(i+1-t),t );
            break;
        }
    }
    return 0;
}