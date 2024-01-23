#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int n,i,j,tot=0;
    string s;
    double fr=0.0,nu,de;
    cin>>n;
    map<double,int> a;
    a[0.25]=0;
    a[0.5]=0;
    a[0.75]=0;
    for(i=0;i<n;i++)
    {
        cin>>s;
        nu=s[0]-'0';
        de=s[2]-'0';
        fr=nu/de;
        a[fr]++;
    }
    tot+=a[0.5]/2;
    a[0.5]=a[0.5]%2;
    while(a[0.25]!=0 && a[0.75]!=0)
    {
        tot+=1;
        a[0.25]--;
        a[0.75]--;
    }
    if(a[0.75]!=0)
    {
        while(a[0.75]!=0)
        {
            tot+=1;
            a[0.75]--;
        }

    }
    if(a[0.25]!=0)
    {
        if(a[0.5]==1)
        {
            tot+=1;
            a[0.5]=0;
            a[0.25]-=2;
        }
        if(a[0.25]>0)
        {
            tot+=a[0.25]/4;
            a[0.25]=a[0.25]%4;
        }
        if(a[0.25]>0)
        {
            tot+=1;
        }
    }
    if(a[0.5]>0)
    {
        tot+=1;
    }
    printf("%d\n",(tot+1));
    return 0;
}
