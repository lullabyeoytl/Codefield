#include <cstdio>
#include <cstring>
int A[100005];int B[100005]; int C[100005];
int w(int a, int b , int c)
{
    if(a<=0 || b <= 0 || c <= 0)
    return 1;
    else if (a >20 || b> 20 || c >20)
    return w(20 , 20 ,20);
    else if (a< b && b <c)
     return w(a-1 , b , c-1)+w(a,b-1,c-1)-w(a,b-1,c);
     else
     return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
int main(void)
{
    int i = 1;
    do
    {
         scanf("%d%d%d", &A[i],&B[i],&C[i]);
        i++;
    } while (A[i] != -1 &&B[i] != -1 &&C[i] != -1);
    
        //i 表示行数
    for(int j = 1 ; j<=i -1 ; j++)
    printf("w(%d , %d, %d) = %d" , A[j] , B[j], C[j], w(A[j], B[j], C[j]));
    getchar();
    return 0;
} //误入记忆化搜索，还要回首