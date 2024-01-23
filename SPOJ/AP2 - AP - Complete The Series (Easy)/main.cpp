#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long int t,th,thl,sum,n,a,d,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&th,&thl,&sum);
        n=(2*sum)/(th+thl);
        d=(th-thl)/(5-n);
        a=th-(2*d);
        printf("%lld\n",n);
        for(i=1;i<n;i++)
        {
            printf("%lld ",(a+(i-1)*d));
        }
        printf("%lld\n",(a+(n-1)*d));
    }
    return 0;
}
