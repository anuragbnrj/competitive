#include <bits/stdc++.h>
using namespace std;

int arr[10004];
long dp[10004];

long max(long a, long b)
{
    return (a>b?a:b);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k, i;
        long mx=-1e9;
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        dp[0]=1l*arr[0];
        for(i=1;i<=k;i++)
        {
            dp[i]= max( 1l*arr[i] , dp[i-1] );
        }
        for(i=k+1;i<n;i++)
        {
            dp[i]= max( dp[i-1] , max ( 1l*arr[i] , 1l*arr[i]+dp[i-k-1])  );
        }
        cout<< 1l*max(0,dp[n-1]) <<endl;
    }
    return 0;
}
