#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int mx=31700;



int main()
{
    int t, m, n, i;
    cin>>t;

    while(t--)
    {
       cin>>m>>n;
       seg_sieve(m,n);
       cout<<endl;
    }
    return 0;
}
