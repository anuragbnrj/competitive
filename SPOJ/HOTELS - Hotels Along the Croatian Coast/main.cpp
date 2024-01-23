#include <cstdio>

using namespace std;

int hpr[300002];

int max(int a,int b)
{
    return (a>b ? a:b);
}
int main()
{
    int n,m,i,beg=1;
    long long mx=0,sum=0;
    scanf ("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&hpr[i]);
    }
    for(i=1;i<=n;i++)
    {
        sum=sum+hpr[i];
        while(sum>m)
        {
            sum=sum-hpr[beg++];
        }
        mx=max(mx,sum);
    }
    printf("%lld\n",mx);
    return 0;
}
