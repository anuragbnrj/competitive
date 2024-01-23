#include <bits/stdc++.h>
using namespace std;

long long powr[60];
vector<long long > v;

int main()
{
    int t;
    long long l, temp=0, i, j, num;
    powr[0]=1;
    for(i=1;i<60;i++)
    {
        powr[i]=powr[i-1]<<1;
    }
    for(i=59;i>=1;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            num=powr[i]+powr[j];
            v.push_back(num);
            num=0;
        }
    }

    l=v.size();
    //sort(v.begin(),v.end());
    /*for(i=0;i<=20;i++)
    {
        cout<<v[i]<<": ";
    }
    cout<<endl;*/

    scanf("%d", &t);
    while(t--)
    {
    	long long n, sum=0;
    	scanf("%lld",&n);
    	for(i=0;i<l;i++)
        {
            if(v[i]<=n)
            {
                sum=(sum+v[i])%1000000007;
            }
        }
    	printf("%lld\n",sum);
    }
    return 0;
}
