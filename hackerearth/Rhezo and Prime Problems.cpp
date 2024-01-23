#include <bits/stdc++.h>
using namespace std;

int lrpr(int n)
{
    int k, j, f=0;
    for(k=n;k>=2;k--)
    {
        f=0;
        for(j=1;j<k;j++)
            if(k%j==0){f++;}
        if(f==1){return k;}
    }
}

int main()
{
    int n, i, j, s=0, mx=0;
    long arr[5002];
    arr[0]=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    if(n==1)
    {
        cout<<"0"<<endl;
    }
    else
    {
        int p=lrpr(n);
        for(i=1;i<=p;i++)
        {
            s=s+arr[i];
            if(s>mx){mx=s;}
        }
        j=1;
        for(i=p+1;i<=n;i++)
        {
            s=s+arr[i]-arr[j];
            if(s>mx){mx=s;}
        }
        cout<<mx<<endl;
    }
    return 0;
}
