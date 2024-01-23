#include <iostream>
#include <cstdio>

int max(int a,int b){return (a>b ? a:b);}

using namespace std;

int t[52][1010],wt[52],v[52];

int main()
{
    int n,k,m,i,w;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&k,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&wt[i],&v[i]);
        }
        for(i=0;i<=m;i++)
        {
            for(w=0;w<=k;w++)
            {
                if(i==0 || w==0)
                    t[i][w]=0;
                else if(wt[i]>w)
                    t[i][w]=t[i-1][w];
                else
                    t[i][w]=max(t[i-1][w],v[i]+t[i-1][w-wt[i]]);
            }
        }
        printf("Hey stupid robber, you can get %d.\n",t[m][k]);
    }
    return 0;
}
