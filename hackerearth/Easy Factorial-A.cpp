#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=23, i, mod=14567;
    long long res=1;
    for(i=1;i<=23;i++)
    {
        res=(res*i*1ll)%mod;
    }
    cout<<1ll*res<<endl;
    return 0;
}
