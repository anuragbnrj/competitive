#include <iostream>
#include <cstdio>
using namespace std;

int n, q, a[100005], b[100005];
//long long sa[100005], sb[100005];

int main()
{
    int l, r, i, d, j, c;
    long long sum=0;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d", &b[i]);
    }
    /*sa[1]=a[1];sa[2]=a[2];
    for(i=3;i<=n;i++)
    {
        sa[i]=sa[i-2]+a[i];
    }
    sb[1]=b[1];sb[2]=b[2];
    for(i=3;i<=n;i++)
    {
        sb[i]=sb[i-2]+b[i];
    }*/
    for(i=1;i<=q;i++)
    {
        scanf("%d %d %d", &d, &l, &r);
        if(d==1)
        {
            c=1;sum=0;
            for(j=l;j<=r;j++)
            {
                if(c==1){sum+=a[j];c=1-c;}
                else{sum+=b[j];c=1-c;}
            }
        }
        else
        {
            c=1;sum=0;
            for(j=l;j<=r;j++)
            {
                if(c==1){sum+=b[j];c=1-c;}
                else{sum+=a[j];c=1-c;}
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}

