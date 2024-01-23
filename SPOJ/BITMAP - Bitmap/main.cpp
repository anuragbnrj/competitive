#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int abs(int a){return( a>0?a:(a*(-1)) );}

bool vis[185][185];
int a[185][185],tr,tc;
int x[]={0,1,0,-1};
int y[]={1,0,-1,0};

int bfs(int r,int c)
{
    queue<pair<int,int> > q;
    pair<int,int> fr;
    q.push(make_pair(r,c));
    int rw=0,cl=0,i;
    while(!q.empty())
    {
        fr = q.front();
        q.pop();
        vis[fr.first][fr.second]=true;
        if(a[fr.first][fr.second]==1)
        {
            return(abs((fr.first)-r)+abs((fr.second)-c));
        }
        for(i=0;i<4;i++)
        {
            rw=fr.first+y[i];
            cl=fr.second+x[i];
            if(rw>=tr || rw<0 || cl>=tc || cl<0 || vis[rw][cl])
            {
                continue;
            }
            else
            {
                q.push(make_pair(rw,cl));
            }
        }
    }
    return 0;
}

int main()
{
    int t,dis;
    scanf("%d",&t);
    while(t--)
    {
        int i,j;
        string s;
        scanf("%d %d",&tr,&tc);
        for(i=0;i<tr;i++)
        {
            cin>>s;
            for(j=0;j<tc;j++)
            {
                char ch=s[j];
                a[i][j]=ch-'0';
            }
        }
        for(i=0;i<tr;i++)
        {
            for(j=0;j<tc;j++)
            {
                memset(vis,false,sizeof(vis));
                dis=bfs(i,j);
                printf("%d ",dis);
            }
            printf("\n");
        }
    }
    return 0;
}
