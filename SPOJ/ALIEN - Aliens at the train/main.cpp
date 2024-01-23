#include <cstdio>

using namespace std;

int hpr[300002];

int max(int a,int b)
{
    return (a>b ? a:b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,i,beg=1,st=0,fin=0,tr=0,mxtr=0;
        long long mx=0,sum=0;
        scanf ("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&hpr[i]);
        }
        for(i=1;i<=n;i++)
        {
            sum=sum+hpr[i];
            tr++;
            while(sum>m)
            {
                sum=sum-hpr[beg++];
                tr--;
            }
            if(sum>mx && tr >=mxtr)
            {
                mx=sum;
                fin=i;
                st = (beg==1) ? beg:(beg-1);
            }
        }
        printf("%lld %d\n",mx,(fin-st));
    }
    return 0;
}
