#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long> > v;

bool srt(const pair<long long, long long> &a,
               const pair<long long, long long> &b)
{
       return (a.first <b.first);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

    	int n, i;
    	long long num,b;
    	cin>>n;
    	for(i=0;i<n;i++)
    	{
    		cin>>num;
    		b=__builtin_popcountll(num);
    		v.push_back(make_pair(b,num));
    	}
    	stable_sort(v.begin(),v.end(),srt);
    	for(i=0;i<v.size()-1;i++)
    	{
    		cout<<v[i].second<<" ";
    	}
    	cout<<v[i].second<<endl;
    	v.clear();
    }
    return 0;
}
