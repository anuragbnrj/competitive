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
    int t=1;
    cin>>t;
    while(t--)
    {
        cin>>V;
        E=V-1;
        int w=0,lrd=-1,frv=0;
        AdjList.assign(V+1, vii());
        for (int i = 0; i < E; i++)
        {
            scanf("%d %d%d", &a, &b, &w);
            a--;b--;
            AdjList[a].push_back(ii(b, w));
            AdjList[b].push_back(ii(a, w));
        }

        s=0;
        vi dist(V, 1000000000); dist[s] = 0;
        queue<int> q; q.push(s);

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                ii v = AdjList[u][j];
                if (dist[v.first] == 1000000000)
                {
                    dist[v.first] = dist[u] + v.second;
                    if(dist[v.first]>lrd)
                    {
                        lrd=dist[v.first];
                        frv=v.first;
                    }
                    q.push(v.first);
                }
            }
        }

        s=frv;
        dist.assign(V, 1000000000); dist[s] = 0;
        q= queue<int> (); q.push(s);lrd=-1;frv=0;
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                ii v = AdjList[u][j];
                if (dist[v.first] == 1000000000)
                {
                    dist[v.first] = dist[u] + v.second;
                    if(dist[v.first]>lrd)
                    {
                        lrd=dist[v.first];
                        frv=v.first;
                    }
                    q.push(v.first);
                }
            }
        }
        printf("%d\n",lrd);
    }
    return 0;
}
