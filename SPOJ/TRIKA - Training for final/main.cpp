#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int min(int a, int b){return (a<b?a:b);}

int main()
{
    int n, m, arr[23][23], x, y, i, j, a, b;
    cin>>n>>m;
    cin>>x>>y;
    memset(arr,999999,sizeof(arr));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(i=x;i<=n;i++)
    {
        for(j=y;j<=m;j++)
        {
            if((i==x && j==y)|| (i==(x+1) && j==y) || (i==x && j==(y+1)))
                continue;
            else if(i==x){arr[i][j]+=arr[i][j-1];}
            else if(j==y){arr[i][j]+=arr[i-1][j];}
            else
            {
                a=arr[i-1][j];
                b=arr[i][j-1];
                arr[i][j]+=min(a,b);
            }
        }
    }
    if(arr[m][n]<=arr[x][y]){printf("Y %d\n",(arr[x][y]-arr[m][n]));}
    else{printf("N\n");}
    return 0;
}
