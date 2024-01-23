#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, arr[101], i;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        if(n==1){cout<<arr[0]<<endl;}
        else{cout<<"0"<<endl;}
    }
    return 0;
}
