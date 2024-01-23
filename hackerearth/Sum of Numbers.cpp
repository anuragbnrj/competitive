#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, arr[16];
    cin>>t;
    while(t--)
    {
        int n, i, j, sum=0, flag=0, s;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>s;
        for(i = 0;i < (1 << n); ++i)
        {
            sum=0;
            for(int j = 0;j < n;++j)
            {
                if(i & (1 << j))
                {
                    sum+=arr[j];
                }
            }
            if(sum==s)
            {
                flag=1;
                break;
            }
        }
        if(flag==1){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
    return 0;
}
