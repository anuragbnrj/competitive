#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define DFS_WHITE -1
#define DFS_BLACK 1

vector<vii> AdjList;
vi dfs_num;
int numCC;

void dfs(int u)
{
    dfs_num[u] = DFS_BLACK;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            dfs(v.first);
    }
}

int main()
{
    int V, E, a, b;
    scanf("%d %d", &V, &E);
    AdjList.assign(V, vii());
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &a, &b);
        a--;b--;
        AdjList[a].push_back(ii(b, 0));
        AdjList[b].push_back(ii(a, 0));
    }
    numCC = 0;
    dfs_num.assign(V, DFS_WHITE);
    for (int i = 0; i < V; i++)
    {
        if (dfs_num[i] == DFS_WHITE)
        {
            ++numCC;
            dfs(i);
        }
    }
    if(numCC==1 && E==(V-1))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}
