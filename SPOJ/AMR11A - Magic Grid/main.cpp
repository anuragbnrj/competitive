#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int min(int a, int b){return (a<b?a:b);}
int max(int a, int b){return (a>b?a:b);}

int arr[502][502],dp[502][502];

int main()
{
    int t, r, c, i, j, mn, a, b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &r, &c);
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        mn=0;dp[1][1]=0;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(i==1){arr[i][j]+=arr[i][j-1];mn=dp[i][j-1];dp[i][j]=min(arr[i][j],mn);}
                else if(j==1){arr[i][j]+=arr[i-1][j];mn=dp[i-1][j];dp[i][j]=min(arr[i][j],mn);}
                else{arr[i][j]+=max(arr[i-1][j],arr[i][j-1]);mn=max(dp[i-1][j],dp[i][j-1]);dp[i][j]=min(arr[i][j],mn);}
            }
        }

        printf("%d\n",(dp[r][c]*(-1)+1));
    }
    return 0;
}
