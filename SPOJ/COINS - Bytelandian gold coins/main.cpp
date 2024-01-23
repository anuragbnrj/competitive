#include <cstdio>
#include <map>

using namespace std;

map<long , long long > dp;

long long  mx(long n)
{
    if(n==0) return 0;
    if(dp[n]!=0) return(dp[n]);

    else
    {
        long long temp = (mx(n/2)+mx(n/3)+mx(n/4));
        dp[n]=(temp > n ? temp:n);
        return dp[n];
    }
}

int main()
{
    long c;
    while(scanf("%ld",&c)!=EOF)
    {
        printf("%lld\n",mx(c));
    }
    return 0;
}
