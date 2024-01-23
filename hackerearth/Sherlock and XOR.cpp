#include <bits/stdc++.h>
using namespace std;

long arr[100005];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, i, j, c=0, o=0, e=0;
        long temp;
        scanf("%d", &n);
        for(i=0;i<n;i++)
        {
            scanf("%ld",&arr[i]);
        }
        for(i=0;i<n;i++)
        {
            if( (arr[i] & 1 )==1)
            {
                o++;
            }
            else
            {
                e++;
            }
        }
        printf("%lld\n",1LL*o*e);
    }
    return 0;
}
