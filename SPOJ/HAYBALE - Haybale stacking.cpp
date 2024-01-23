#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int a[1000006];

int main()
{
    int n, k, l, r, i, sum=0;
    cin>>n>>k;
    for(i=0;i<1000006;i++)
    {
        a[i]=0;
    }

    while(k--)
    {
        cin>>l>>r;
        a[l]+= 1;
        a[r+1] += -1;
    }

    for(i=1;i<=n;i++)
    {
        sum += a[i];
        a[i]=sum;
    }
    sort(a+1, a+n+1);
    /*for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" ; ";
    }
    cout<<endl;*/
    cout<<a[(n+1)/2]<<endl;
    return 0;
}
