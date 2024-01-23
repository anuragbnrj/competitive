#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;


int fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M)
{
    return fast_pow(n,M-2,M);
}


int main()
{
    int t, arr[16], cas_no=1;
    cin>>t;
    while(t--)
    {
        int n, i, j, nu=1, de=0, de_mmi=0, mx=0, csb=0, ex=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(i = 0;i < (1 << n); ++i)
        {
            nu=1;
            csb=0;
            de=0;
            for(int j = 0;j < n;++j)
            {
                if(i & (1 << j))
                {
                    csb++;
                    de=(de+arr[j]);
                }
            }
            if(csb>1)
            {
                ex=1;
                de_mmi=findMMI_fermat(de,MOD);
                for(int j = 0;j < n;++j)
                {
                    if(i & (1 << j))
                    {
                        ex=(ex*arr[j])%MOD;
                        ex=(ex*de_mmi)%MOD;
                    }
                }
                ex=(nu*de_mmi)%MOD;
                if(ex>=mx){mx=ex;}
            }
        }
        printf("Case #%d: %d\n", cas_no++, mx);
    }
    return 0;
}
