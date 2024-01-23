#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
	int d,f,tc,n,i,count;
	pair<int,int> stops[10002];

	scanf("%d",&tc);
	while(tc--)
	{
	    count=0;
	    priority_queue<int> q;
	    scanf("%d",&n);
	    for(i=0;i<n;i++)
	    {
	        scanf("%d %d",&d,&f);
	        stops[i]=make_pair(d,f);
	    }
	    scanf("%d %d",&d,&f);
	    for(i=0;i<n;i++)
	    {
	        stops[i].first=d-stops[i].first;
	    }
	    sort(stops,stops+n);
	    stops[n]=make_pair(d,0);
	    for(i=0;i<n+1;i++)
	    {
	        while(f<stops[i].first && !q.empty())
	        {
	            f+=q.top();q.pop();
	            count++;
	        }
	        if(f<stops[i].first)
	        {break;}
	        q.push(stops[i].second);
	    }
	    if(f<d){printf("-1\n");}
	    else {printf("%d\n",count);}
	}
	return 0;
}
