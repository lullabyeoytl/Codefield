/*
#include <cstdio>
#include <cstring>
int bol[505]; int mo [505][505] ;int lun[505];
int resmax1=0;int resmax2=0;
int main()
{
    memset(mo , 0, sizeof(mo));
    int n;
    scanf("%d" ,&n);
    for(int i= 1; i<=n-1;i++)
    {
        for(int j =i+1; j<=n; j++)
        {
            scanf("%d" ,&mo[i][j]); //mo[x][y] x<y
            mo[j][i] = mo[i][j];
        }
    }
    memset(bol , 0, sizeof(bol));
    for(int j = 1; j<= n; j++)//计轮次1
    {
        int max1=-1; int max2=-1;
        bol[j]  =1;lun[1] = j;
        int max  =-1;int targ = 0;
        for(int k =1; k<= n ; k++ )
        {
            if(mo[j][k] >= max )
            {
                targ = k;
                max = mo[j][k];
            }
            bol[targ] = -1; lun[2] =targ;
        }
        for(int i = 2; i<=n/2; i++)
        {
            /*
             int target = 0;
            for(int l = 1; l<= n; l++)
            {
                int maxn = -1;
                for(int q = 1; q<=n;q++)
                {
                    if (bol[q] != 1)
                    continue;
                  else if(bol[l] == 0 && mo[q][l] >= maxn)
                    {
                     maxn = mo[lun[q]][l];
                     target = l;  //对于q选最好的l
                    }
               }
              bol[target] = 1; lun[2*i-1] = target;
            }
            */
            //下模拟电脑；
            /*
            int imax = -1;
            for(int b = 1; b<= n; b++)
            {
                if(bol[b] != 1)
                continue;
                int randmax = -1; int randtar = 0;
                for(int c = 1; c<=n;c++)
                {
                    if(bol[c] == 0&& mo[b][c] >=randmax )
                    {
                        randmax = mo[b][c];
                        randtar = c;
                    }
                    else 
                    continue;
                }
                if(randmax >= imax)
                {
                    imax = randmax;
                    lun[2*i-1] = randtar;
                }
                else continue;
            }
            bol[lun[2*i-1]] = 1;



            int maxn = -1;int ctarget;
             for(int l = 1; l<= n; l++)
            {
                
                if(bol[l] == 0 && mo[lun[2*i-1]][l] >= maxn)
                {
                    maxn = mo[lun[2*i-3]][l];
                    ctarget = l;
                }
            }
            bol[ctarget] = -1; lun[2*i] = ctarget;
        }

        for(int w = 1; w<= n/2-1; w++)
        {
           for(int e = w+1; e<=n/2;e++)
           {
            if(mo[lun[2*e-1]][lun[2*w-1]] >= max1)
            {
                max1 = mo[lun[2*e-1]][lun[2*w-1]];
            }
            if(mo[lun[2*e]][lun[2*w]] >= max2)
             max2 = mo[lun[2*e]][lun[2*w]];
           }
        }
        if(max1 > max2)
        resmax1 = max1;
        else
        continue;

    }
    if(resmax1==0)printf("0");
    else
    {
        printf("1\n");
        printf("%d", resmax1);
    }
    return 0;
}
*/
//教训：先想清楚了再码！