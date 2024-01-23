#include <iostream>
#include <cstring>
#include <algorithm>
long long grval(int , int );

using namespace std;

long long cache[2002][2002],n;
int a[2000];

int main()
{
    int i,beg,en;
    cin>>n;
    memset(cache,-1,sizeof(cache));
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<grval(0,n-1);
    return 0;
}

long long grval(int beg,int en)
{
    if(beg>en)
        return 0;

    else if (cache[beg][en]!=(-1))
        return cache[beg][en];

    else
        return cache[beg][en]=
         max(a[beg]*(n-(en-beg+1)+1)+grval(beg+1,en),
             a[en]*(n-(en-beg+1)+1)+grval(beg,en-1));
}
