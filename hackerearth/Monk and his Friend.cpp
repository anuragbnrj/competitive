#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	long long p, m, diff, ans;
    	cin>>p>>m;
    	diff=p^m;
    	ans=__builtin_popcountll(diff);
    	cout<<ans<<endl;
    }
    return 0;
}
