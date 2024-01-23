#include <bits/stdc++.h>
using namespace std;
int bin[100005];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k, i, tmp, sum=0;
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>tmp;
            bin[i]=__builtin_popcount(tmp);
        }
        sort(bin,bin+n);
        for(i=(n-1);k>=1;k--,i--)
        {
            sum+=bin[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
