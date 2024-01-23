#include <cstdio>
using namespace std;
int mxval[2][2000001];
int max(int a, int b) { return (a > b)? a : b; }
int main()
{
    int k, n, i, w, cur, val[501], wt[501];
    scanf("%d %d", &k, &n);
    for(i=1;i<=n;i++)
        scanf("%d %d", &val[i], &wt[i]);
    for(w=0;w<=k;w++)
    {
        if(wt[1]<=w)
            mxval[0][w] = val[1];

        else
            mxval[0][w] = 0;
    }
    cur=1;
    for(i=2;i<=n;i++)
    {
        for(w=0;w<=k;w++)
        {
            if(wt[i]<= w )
                mxval[cur][w] = max(mxval[!cur][w],val[i]+mxval[!cur][w-wt[i]]);

            else
                mxval[cur][w] = mxval[!cur][w];
        }
        cur=!cur;
    }
    printf("%d\n",mxval[!cur][k]);
    return 0;
}
