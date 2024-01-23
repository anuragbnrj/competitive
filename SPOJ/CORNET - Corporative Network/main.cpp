#include <cstdio>
#include <cstring>
using namespace std;

int par[20002], dpar[20002], dist;

int absdif(int a, int b)
{
    return(a>b ? (a-b):(b-a));
}


void initialize(int N)
{
    for(int i = 1;i<=N;i++)
    {par[ i ] = i ;dpar[i]=0;}
}
int root(int i)
{
    while(par[ i ] != i)
    {
        dist+=dpar[i];
        i = par[ i ];
    }
    return i;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n, a, b;
        char ch[2];
        scanf("%d",&n);
        initialize(n);
        while(scanf("%s", ch)==1 && ch[0]!='O')
        {

            switch(ch[0])
            {
                case 'E':dist=0;
                        scanf("%d",&a);
                        par[a]=root(a);
                        dpar[a]=dist;
                        printf("%d\n",dist);
                        break;

                case 'I':scanf("%d %d", &a, &b);
                        par[a]=b;
                        dpar[a]=absdif(a,b)%1000;
                        break;
            }
        }
    }
    return 0;
}
