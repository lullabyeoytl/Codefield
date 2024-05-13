#include <stdio.h>
int main(void)
{
    int A ,B ,C ,N1, N2;
    for(A=1 ;A <= 9; A++)
    {
        for(B=0; B <= 9; B++)
        {
            for(C=0; C<=9; C++)
            {
                N1=100*A + 10 * B+C;
                N2=A*A*A+B*B*B+C*C*C;
                if(N1==N2)
                printf("%d\n", N1 );
            }
        }
           
    }
    getchar();
    return 0;
}
//反思一：若不计次数，应更多用while
//反思二：其实完全可以从n出发由100到999去检索，A，B,C显然可以用n表示在嵌套if
