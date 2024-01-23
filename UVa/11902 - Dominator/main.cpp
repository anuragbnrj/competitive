#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n,g[100][100],vis[100];

void dfs(int v,int curr)
{
    if(v==curr)
        return;
    vis[v]=1;
    for(int i=0;i<n;i++)
    {
        if(g[v][i]== 1 && vis[i]==0)
            dfs(i,curr);
    }
}

void prl()
{
    printf("+");
    for(int i=0;i<2*n - 1;i++)
        printf("-");
    printf("+\n");

}

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int i,j;
        cin>>n;
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>g[i][j];
            }
        }


        int op[100][100],fvis[100];


        memset(vis,0,sizeof(vis));
        memset(fvis,0,sizeof(fvis));
        dfs(0,1000);

        for(i=0;i<n;i++)
            fvis[i]=vis[i];



        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(0,i);
            for(j=0;j<n;j++)
            {
                if(fvis[j]==1 && vis[j]==0)
                    op[i][j]=1;
                else op[i][j]=0;
            }

        }

        printf("Case %d:\n",cas++);

        for(i=0;i<n;i++)
        {
            prl();
            printf("|");
            for(j=0;j<n;j++)
            {
                if(op[i][j])
                    printf("Y|");
                else
                    printf("N|");
            }
            printf("\n");
        }
        prl();
    }
    return 0;
}
