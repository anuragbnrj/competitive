#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int budg,nop,cop[110],fop[110],totfun[101][501];
    while( (scanf("%d %d",&budg,&nop)) && budg && nop )
    {
        int i,j,entfee=0,tmp=0;

        for(i=1;i<=nop;i++)
            scanf("%d %d",&cop[i],&fop[i]);

        for(i=0;i<=budg;i++)
            totfun[0][i]=0;

        for(i=1;i<=nop;i++)
            totfun[i][0]=0;

        for(i=1;i<=nop;i++)
        {
            for(j=1;j<=budg;j++)
            {
                if(cop[i]<= j)
                {
                    totfun[i][j] = max(totfun[i-1][j],fop[i]+totfun[i-1][j-cop[i]]);
                }

                else
                    totfun[i][j] = totfun[i-1][j];
            }
        }
        tmp= totfun[nop][budg];
        for(i=1;i<=budg;i++)
        {
            if(totfun[nop][i]== tmp)
            {
                entfee=i;
                break;
            }
        }
        printf("%d %d\n",entfee,totfun[nop][budg]);
    }
    return 0;
}
