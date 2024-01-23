#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int g[101][101],dfs_num[101],n;

void dfs(int ver,int beg)
{
    if(ver==beg && dfs_num[ver]==2)
        dfs_num[ver]=1;

    else if(ver==beg)
        dfs_num[ver]=2;

    else
        dfs_num[ver]=1;

    for(int k=1;k<=n;k++)
    {
        if(g[ver][k]==1 && dfs_num[k]!=1)
        {
            int ve=k;
            dfs(ve,beg);
        }
    }
}

void prt()
{
    int cnt=0;
    for(int k=1;k<=n;k++)
    {
        if(dfs_num[k]!=1)
            cnt++;
    }
    printf("%d",cnt);
    for(int k=1;k<=n;k++)
    {
        if(dfs_num[k]!=1)
            printf(" %d",k);
    }
    printf("\n");
}

int main()
{
    int i,j,chk;
    while(true)
    {
        cin>>n;
        if(n==0){break;}
        int v,v1,vk;
        memset(g,0,sizeof(g));
        for(;;)
        {
            cin>>v1;
            if(v1==0){break;}
            for(;;)
            {
                cin>>vk;
                if(vk==0){break;}
                g[v1][vk]=1;
            }
        }
        cin>>chk;
        for(i=1;i<=chk;i++)
        {
            cin>>v;
            memset(dfs_num,0,sizeof(dfs_num));
            dfs(v,v);
            prt();
        }
    }
    return 0;
}
