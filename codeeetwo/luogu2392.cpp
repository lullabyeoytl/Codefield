#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int A[25],B[25],C[25],D[25];

int thi(int a[] , int n)
{
    int sum = 0;
    if(n>=2)
    {   
        a[n-1]= abs(a[n]-a[n-1]);
        sum += min(a[n],a[n-1]);
        if((a[n]-a[n-1])!=0)
        thi(a,n-1);
        else
        thi(a,n-2);
    }
    if(n==1)
    {
    sum+=a[1];
    return sum;
    }
    if(n==0)
    return sum;
}
int main()
{
    int s1,s2,s3,s4;
    scanf("%d%d%d%d",&s1,&s2,&s3,&s4);
    for(int i = 1; i<=s1;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i = 1; i<=s2;i++)
    {
        scanf("%d",&B[i]);
    }
    for(int i = 1; i<=s3;i++)
    {
        scanf("%d",&C[i]);
    }
    for(int i = 1; i<=s4;i++)
    {
        scanf("%d",&D[i]);
    }
    int sum1 = thi(A , s1);
    int sum2 =thi(B , s2);
    int sum3 =thi(C, s3);
    int sum4 =thi(D , s4);
    printf("%d",sum1+sum2+sum3+sum4);
    getchar();
    return 0;

}