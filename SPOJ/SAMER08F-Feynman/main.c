#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    long long int sum=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        sum=n*(n+1)*(2*n+1)/6;
        printf("%lld\n",sum);
    }
    return 0;
}
