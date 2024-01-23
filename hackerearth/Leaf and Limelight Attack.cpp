#include <bits/stdc++.h>
#define mod 1000000009
using namespace std;

int cache[10000007];


int prec()
{
    int i=2,j;
    long long sum=0, mx;
    for(i=2;i<=10000000;i++)
    {
        sum=0;
        mx=(1ll*i*i)%mod;
        for(j=1;j<=4;j++)
        {
            sum=(sum+mx)%mod;
            mx=mx-i+1;
        }

        cache[i]=(cache[i-2]+sum)%mod;
    }
}

/*int calc(int d)
{
    if(cache[d]!=0)
    {
        return cache[d];
    }
    else
    {
        if(d<1)
        {
            return 0;
        }
        else
        {
            int j;
            long long sum=0, mx;
            mx=(1ll*d*d)%mod;
            for(j=1;j<=4;j++)
            {
                sum=(sum+mx)%mod;
                mx=mx-d+1;
            }
            return (cache[d]=(sum+calc(d-2))%mod);
        }
    }
}*/

int main()
{
    int t, n;
    cache[0]=0;
    cache[1]=1;
    prec();
    cin>>t;
    prec();
    while(t--)
    {
        cin>>n;
        cout<< cache[n]<< endl;
    }
    return 0;
}



