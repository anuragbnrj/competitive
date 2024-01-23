#include <bits/stdc++.h>
using namespace std;

int modInverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {

        q = a / m;

        t = m;


        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    if (x1 < 0)
       x1 += m0;

    return x1;
}

int main()
{
    int n, mx, mn, i;
    long long mod=1000000000+7, res=1, nu, de, mmi;
    cin>>n;
    mx=max(6,n-6);
    mn=n-mx;
    nu=mx+1;
    de=1;
    for(i=1;i<=mn;i++)
    {
        mmi= modInverse(de,mod);
        res=( ((res*nu)%mod) * (mmi%mod) )%mod;
        nu++;
        de++;
    }

    printf("%lld", res);
    return 0;
}
