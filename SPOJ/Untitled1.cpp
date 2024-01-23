#include <cstdio>
#include <iostream>

using namespace std;


int main()
{
    int a[100005];
    int t, n, u, l, r, val, q, pos, i;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n, &u);
        for(i=0;i<=n+1;i++)
        {
            a[i]=0;
        }
        while(u--)
        {
            scanf("%d %d %d", &l, &r, &val);
            a[l+1]+=val;
            a[r+2]-=val;
        }
        for(i=1;i<=n;i++)
        {
            a[i]+=a[i-1];
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d", &pos);
            printf("%d\n", a[pos+1]);
        }
    }
    return 0;
}
