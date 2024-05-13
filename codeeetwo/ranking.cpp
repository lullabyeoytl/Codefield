/*#include <stdio.h>
int main (void)
{
    int  A[10000000005];  int N;
    scanf ("%d" , &N);
    for (int i = 1; i <= N ; i++)
    scanf("%d" ,&A[i]);
for (int i = 0; i < N - 1; i++)

for (int j = i + 1; j < N; j++)

if (A[j] < A[i])
{
    int b =A[j];
    A[j]=A[i];
    A[i]=b;
}

for(int i = 1; i<= N ; i++)
printf("%d" , A[i]);
return 0;
}*/
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a,int b){
     return a<b;
}
int main()
{  
     long long int N; long long int A[1000000005]  ;
     cin>>N;
     for(int i =1 ; i<=N; i++)
     cin>> A[i];
     sort(A,A+N,compare); //compare指定排序规则
     for(int i=1; i<N; i++)
        cout<<A[i]<<endl;
     return 0;
}