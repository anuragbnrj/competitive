#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int x[9]={0,-1,-2,-2,-1,1,2,2,1};
int y[9]={0,-2,-1,1,2,2,1,-1,-2};

int bfs(int a1,int  b1,int a2,int b2)
{
    int moves[9][9],vis [9][9],m,n;
    pair<int,int> p;
    queue< pair<int,int> > q;
    memset(moves,0,sizeof moves);
    memset(vis,0,sizeof vis);
    p.first = a1;
    p.second = b1;
    q.push(p);
    vis[a1][b1]=0;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p.first== a2 && p.second == b2)
            printf("%d",moves[a2][b2]);
        for(int i=1;i<=8;i++)
        {
            m=p.first+x[i];n=p.second+y[i];
            if(m>8 || m<1 || n>8 || n<1   )
            {
                continue;
            }
            else
            {
                q.push(make_pair(m,n));
                vis[m][n] = 1;
                moves[m][n]=moves[p.first][p.second] + 1;
            }
        }
    }


}
int main()
{
    char a1,a2;
    int b1,b2;
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%c %d %c %d",&a1,&b1,&a2,&b2);
        bfs(a1-'a'+1,b1,a2-'a'+1,b2);
        printf("\n");
    }
    return 0;
}
