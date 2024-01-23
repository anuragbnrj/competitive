#include <iostream>
#include <cstdio>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

int main()
{
    int t, h, w, arr[101][101], i, j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &h, &w);
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        for(i=1;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                int a=0, b=0, c=0;
                if(j-1>=0){a=arr[i-1][j-1];}
                if(j+1<w){c=arr[i-1][j+1];}
                b=arr[i-1][j];
                arr[i][j]+=max(a,max(b,c));
            }
        }
        for(j=1;j<w;j++)
        {
            arr[h-1][j]=max(arr[h-1][j],arr[h-1][j-1]);
        }
        printf("%d\n",arr[h-1][w-1]);
    }
    return 0;
}
