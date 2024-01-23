#include <bits/stdc++.h>
using namespace std;

int arr[10004];

long long max(long long a, long long b)
{
    return(a>b? a:b);
}

int main()
{
    int t, c=0;
    cin>>t;
    while(t--)
    {
        int n, i;long long inc=0, exc=0, temp=0;
        cin>>n;
        c++;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        inc=arr[0];
        for(i=1;i<n;i++)
        {
            temp=exc;
            exc=max(inc,exc);
            inc=temp+arr[i];
        }
        printf("Case %d: %lld\n", c, max(inc,exc));
    }
    return 0;
}
