#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int id;
    struct Node * next;
}node;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    node * head=(node *)malloc(sizeof(node));
    head->id=1;
    head->next=NULL;
    for(int i=2;i<=n;i++)
    {
        node * p =head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next = (node *) malloc(sizeof(node));
        p->next->id=i;
        if(i==n)
        p->next->next=head;
        else
        p->next->next=NULL;
    }
    node * head1 = head;
    for(int k=1;k<=n;k++)
    {
        node * p = head1;
        for(int ti=1;ti<=m-2;ti++)
        {
            p=p->next;
        }
        printf("%d ",p->next->id);
        head1 = p->next->next;
        p->next=head1;
    }
    free(head1);
    node * pr = NULL;
    node * p =head;
    while(p!=NULL)
    {
        pr=p;
        p=p->next;
        free(pr);
    }
    system("pause");
    return 0;

}
//链表还要复习哦