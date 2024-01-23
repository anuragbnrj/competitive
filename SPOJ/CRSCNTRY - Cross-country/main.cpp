#include <cstdio>

using namespace std;

int agnes[2002],tom[2002];
int dp[2002][2002];

int max(int a, int b){return a > b ? a : b ;}


int lcs(int len1 , int len2)
{
    int i=0,j=0,cur;
    cur=0;
    for(i=0;i<=len1;i++)
    {
        for(j=0;j<=len2;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if (agnes[i-1]==tom[j-1])
                dp[i][j]= 1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        cur=!cur;
    }
    return dp[len1][len2];

}

int main()
{

	int d, len1, len2, n, best;
	scanf("%d", &d);
	while(d--)
	{
		len1 = best = 0;
		while(scanf("%d", &n)==1 && n)
			agnes[len1++] = n;
		while(scanf("%d", &n)==1 && n)
		{
			len2 = 0;
			tom[len2++] = n;
			while(scanf("%d", &n)==1 && n)
				tom[len2++] = n;
			best = max(best, lcs(len1, len2));
		}
		printf("%d\n", best);
	}
	return 0;
}
