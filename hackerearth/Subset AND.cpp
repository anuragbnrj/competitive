#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, num;
    cin>>t;
    while(t--)
    {
        int n, z, i, nd;
        cin>>z>>n;
        nd=z;
        for(i=0;i<n;i++)
        {
            cin>>num;
            nd= nd&num;
        }
        if(nd==0){cout<<"Yes"<<endl;}
        else{cout<<"No"<<endl;}

    }
    return 0;
}
