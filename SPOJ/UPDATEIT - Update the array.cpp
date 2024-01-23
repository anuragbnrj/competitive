/*#include <cstdio>
#include <iostream>
#include <algorithm>*/
#include<bits/stdc++.h>
using namespace std;
  int a[100005];

int main()
{
    cout<<" Hi "<<endl;
    int t, n, u, l, r, val, q, pos, i;
    cin>>t;

    while(t--)
    {
        cin>>n>>u;
        for(i=0;i<=n+1;i++)
        {
            a[i]=0;
        }
        while(u--)
        {
            cin>>l>>r>>val;
            a[l+1]+=val;
            a[r+2]-=val;
        }
        for(i=1;i<=n;i++)
        {
            a[i]+=a[i-1];
        }
        cin>>q;
        while(q--)
        {
            cin>>pos;
            cout<<a[pos+1]<<endl;
        }
    }
    return 0;
}
