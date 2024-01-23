#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int V, E, a, b, s;
vector<vii> AdjList;

int main()
{
    int t,k=1;
    cin>>t;
    while(t--)
    {
        scanf("%d %d",&V,&E);
        AdjList.assign(V, vii());
        for (int i = 0; i < E; i++)
        {
            scanf("%d %d", &a, &b);
            a--;b--;
            AdjList[a].push_back(ii(b, 0));
            AdjList[b].push_back(ii(a, 0));
        }

        vi col(V, 1000000000);
        queue<int> q;
        bool isBipartite = true;
        vector<bool> vis(V,false);
        for (int i = 0; i < V && isBipartite; i++)
        {
            if(!vis[i])
            {
                q.push(i);vis[i]=true;
                col[i] = 0;
                while (!q.empty()&& isBipartite)
                {
                    int u = q.front(); q.pop();
                    for (int j = 0; j < (int)AdjList[u].size(); j++)
                    {
                        ii v = AdjList[u][j];
                        if (col[v.first] == 1000000000)
                        {
                            col[v.first] = 1 - col[u];
                            q.push(v.first);vis[v.first]=true;
                        }
                        else if (col[v.first]  == col[u] )
                        {
                            isBipartite = false;
                            break;
                        }
                    }
                }
            }
        }
        if(isBipartite)
        {
            printf("Scenario #%d:\n",k++);
            printf("No suspicious bugs found!\n");
        }
        else
        {
            printf("Scenario #%d:\n",k++);
            printf("Suspicious bugs found!\n");
        }
    }
    return 0;
}
