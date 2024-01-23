#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

#define MX 505

int dp[10005];
int weight[MX];
int cost[MX];

int main()
{
	int i,n,k,j,t;
	scanf("%d",&t);
	while(t--)
    {
	  scanf("%d %d",&n,&k);
	  for(i=1;i<=k;i++)
	  {
	    scanf("%d",&cost[i]);
	  }
	  dp[0]=0;
	  for(i=1;i<=k;i++)
	  {
	    dp[i]=INT_MAX;
	    for(j=1;j<=i;j++)
	    {
	        if( dp[ i-j ] !=INT_MAX && cost[j]!=-1)
	        {
	           dp[i] = min(dp[i],dp[i - j] + cost[j]);
	        }
	    }
	  }
	  if(dp[k]==INT_MAX)printf("-1\n");
	  else printf("%d\n",dp[k]);
	}
  return 0;
}
