#include <bits/stdc++.h>
using namespace std;

long maxfn(long a, long b)
{
    return(a>b?a:b);
}
int up[1000006], lo[1000006];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l;
        long mx=0, mxm=0;
        cin>>l;
        for(int i=1;i<l;i++)
        {
            cin>>up[i];
        }
        for(int i=1;i<l;i++)
        {
            cin>>lo[i];
        }
        up[l]=0;lo[l]=0;
        for(int i=1;i<=l;i++)
        {
            mx=maxfn( (i+up[i]) , (i+lo[i]) );
            mxm=maxfn( mxm , mx );
        }
        cout<< (mxm) << endl;
    }
    return 0;
}
