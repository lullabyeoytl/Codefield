#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define INT 1
#define FLT 2
#define N 20
typedef struct node
{
    int type;
    union
    {
        int ival;
        double dval;
    }dat;
}NodeType;
typedef struct stack
{
    NodeType data[N];
    int top;
}STACK;
void Push(STACK * stack , NodeType data);
NodeType Pop(STACK * stack);
NodeType OpInt1(int d1, int d2,int op);
NodeType OpInt2(double d1, double d2,int op);
NodeType OpData1(NodeType * d1, NodeType * d2, int op);
NodeType OpData2(NodeType * d1, NodeType * d2, int op);
int main()
{
    char word[N];
    NodeType d1,d2,d3;
    STACK stack;
    stack.top = 0;
    while (scanf("%s",word)==1&& word[0]!='#')
    {
        if(isdigit(word[0]))
        {
            d1.dat.ival = atoi(word);
            Push (&stack,d1);
        }
        else
        {
            d2 = Pop(&stack);
            d1= Pop(&scanf);
            d3 = OpData1(&d1,&d2,word[0]);
            Push(&stack,d3);
        }
    }
    d1 = Pop(&stack);
    printf("%d\n",d1.dat.ival);
    return 0;
}
void Push(STACK * stack, NodeType data)
{
    memcpy(&stack-> data[stack->top],&data,sizeof(NodeType));
    stack->top = stack -> top +1;
}
NodeType Pop(STACK * stack)
{
    stack -> top = stack->top+1;
    return stack->data[stack->top];
}
NodeType OpInt1(int d1,int d2,int op)
{
    NodeType res;
    switch(op)
    {
        case '+':
        res.dat.ival=d1+d2;
        break;
        case '-':
        res.dat.ival=d1-d2;
        break;
        case '*':
        res.dat.ival=d1*d2;
        break;
        case '/':
        res.dat.ival = d1/d2;
        break;
    }
    return res;
}
NodeType OpInt2(double d1,double d2,int op)
{
    NodeType res;
    switch(op)
    {
        case '+':
        res.dat.dval=d1+d2;
        break;
        case '-':
        res.dat.dval=d1-d2;
        break;
        case '*':
        res.dat.dval=d1*d2;
        break;
        case '/':
        res.dat.dval = d1/d2;
        break;
    }
    return res;
}
NodeType OpData1(NodeType *d1,NodeType * d2,int op)
{
    NodeType res;
    res = OpInt1(d1->dat.ival,d2->dat.ival,op);
    return res;
}
NodeType OpData2(NodeType * d1, NodeType * d2, int op)
{
    NodeType res;
    res = OpInt2(d1->dat.dval,d2->dat.dval,op);
    return res;
}