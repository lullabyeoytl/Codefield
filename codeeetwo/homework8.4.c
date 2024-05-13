#include <stdio.h>
#define N 40
int Average( int score[], int n);
int ReadScore(int score[]);
int GetAboveAver (int score[], int n);
int score[N];
int main()
{
    int m,n;
    n = ReadScore(score);
    printf("Total students are %d\n", n);
    m = GetAboveAver(score, n);
    if(m!=-1)printf("Students of above average is %d\n ", m);
    return 0;
}

int Average(int score[], int n)
{
    int i, sum=0;
    for(i=0; i<n;i++)
    {
        sum+=score[i];

    }
    return n>0?sum/n:-1;
}

int ReadScore (int score[])
{
    int i = -1;
    do
    {
        i++;
        printf("Input score:");
        scanf("%d", &score[i]);
    } while (score[i] >= 0);
    return i;
}

int GetAboveAver(int score[], int n)
{
    int i, count = 0; int aver = Average(score,n);
    if(aver == -1)return -1;
    printf("Average score is %d\n",aver);
    for(i=0; i<n; i++)
    {
        if(score[i] >= aver)count ++;
    }
    return count;
}