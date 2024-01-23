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
	int empt,full,W;
	scanf("%d",&t);
	while(t--)
    {
	  scanf("%d %d",&empt,&full);
	  W = full - empt;
	  scanf("%d",&n);
	  for(i=1;i<=n;i++)
	  {
	    scanf("%d %d",&cost[i],&weight[i]);
	  }
	  dp[0]=0;
	  for(i=1;i<=W;i++)
	  {
	    dp[i]=INT_MAX;
	    for(j=1;j<=n;j++)
	    {
	      if(weight[j]<= i )
	      {
	        if( dp[ i-weight[j] ] !=INT_MAX)
	        {
	           dp[i] = min(dp[i],dp[i - weight[j]] + cost[j]);
	        }

	      }
	    }
	  }
	  if(dp[W]==INT_MAX)printf("This is impossible.\n");
	  else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W]);
	}
  return 0;
}
