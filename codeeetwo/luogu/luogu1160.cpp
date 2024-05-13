#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int id;
    struct Node * next;
    struct Node *pre;
}node;
int main()
{
    int n;
    scanf("%d",&n);
    node * head = (node *)malloc(sizeof(node));
    head->id=1;
    head->next=NULL;
    head->pre=NULL;


    for(int i=1;i<=n-1;i++)
    { 
        node * pnew = (node * )malloc(sizeof(node));
        pnew->id=i+1;
        head->next=NULL;
        head->pre=NULL;
        int k,p;
        scanf("%d%d",&k,&p);
        node * pi =head;
        while((pi->id)!=k)
        {
            pi=pi->next;
        }
        if(pi==head&&p==0)
        {
            pnew->next=head;
            head->pre=pnew;
            head=pnew;
        }
        else
        {
            if(p==1&&pi->next==NULL)
            {
                pnew->next=pi->next;

                pi->next->pre=pnew;
                pi->next=pnew;
                pnew->pre=pi;
            }
            else
            {
                if(p==0)
                {
                    pnew->pre=pi->pre;
                    pi->pre->next=pnew;
                    pi->pre=pnew;
                    pnew->next=pi;
                
                }
                if(p==1)
                {
                    pnew->next=pi->next;
                    pi->next->pre=pnew;
                    pi->next=pnew;
                    pnew->pre=pi;
                }
            }
        }
    }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int num;
            scanf("%d",&num);
            node * pr = head;

            while(pr->id!=num)
            {
                pr=pr->next;
            }
            if(pr==head)
            {
                head=pr->next;
                head->pre=NULL;
            }
            else if(pr->next==NULL&&pr->id==num)
            {
                pr->pre->next=NULL;
            }
            else
            {
                if(pr->id==num)
                {
                    pr->next->pre=pr->pre;
                    pr->pre->next=pr->next;
                }
            }
        }
        while(head!=NULL)
            {
                printf("%d ",head->id);
                head=head->next;
            }
        system("pause");
        return 0;
    
}

