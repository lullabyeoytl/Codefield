#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct card
{
    char suit[10];
    char face[10];
}a;
void deal(a * wcard);
void shuffle(a * wcard);
void fillcard(a wcard[] , a * wface[],char * wsuit[]);
int main()
{
    char *suit[] = {"Spades","Hearts","Clubs","Diamonds"};
    char *face[] = {"A","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    a card[52];
    srand(time(NULL));
    fillcard(card,face,suit);
    shuffle(card);
    deal(card);
    system("pause");
    return 0;
}

void fillcard(a wcard[] , a * wface[],char * wsuit[])
{
    int i;
    for(i=0;i<52;i++)
    {
        strcpy(wcard[i].suit,wsuit[i/13]);
        strcpy(wcard[i].face,wface[i%13]);
    }
}
// 这里洗牌的想法是排堆从上到下的牌随机与一张牌交换，主要是题设没讲清什么洗牌方式……
void shuffle (a*wcard)
{
    int i,j;
    a temp;
    for(i=0;i<52;i++)
    {
        j=rand()%52;
        temp =wcard[i];
        wcard[i]=wcard[j];
        wcard[j]=temp;
    }
}

void deal(a*wcard)
{
    int i;
    for(i=0;i<52;i++)
    {
        printf("%9s%9s\n",wcard[i].suit,wcard[i].face);

    }
    
}