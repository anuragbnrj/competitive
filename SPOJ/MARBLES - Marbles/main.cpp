#include <iostream>
#include <cstdio>

int max(int a,int b){return(a>b ? a:b);}

using namespace std;

int main()
{
    int t,n,k,i,j,temp=0;
    cin>>t;
    while(t--)
    {
        double res=1.0;
        cin>>n>>k;
        n=n-1;
        k=k-1;
        temp=max(k,n-k);
        for(i=temp+1,j=1;i<=n;i++,j++)
        {
            res=(res*i)/j;
        }
        printf("%.0lf\n",res);
    }
    return 0;
}
