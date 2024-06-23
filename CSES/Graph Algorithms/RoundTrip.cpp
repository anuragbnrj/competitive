// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;

vector<vector<int>> graph;
vector<int> color;
vector<int> parent;

bool found = false;
vector<int> cycleNodes;

void dfs(int node, int prev) {
    parent[node] = prev;
    color[node] = 1;

    for (int neigh : graph[node]) {
        if (neigh == prev) continue;
        
        if (color[neigh] == 0) {
            dfs(neigh, node);
        } else if (color[neigh] == 1) {
            if (!found) {
                int curr = node;
                vector<int> temp;
                while (curr != neigh) {
                    temp.push_back(curr);
                    curr = parent[curr];
                }
                temp.push_back(curr);
                reverse(temp.begin(), temp.end());

                if (temp.size() >= 3) {
                    found = true;
                    cycleNodes = temp;
                }
            }
        }
    }

    color[node] = 2;
}

void solve() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    color.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i, 0);
        }
    }

    if (found) {
        cout << int(cycleNodes.size()) + 1 << endl;
        for (int i = 0; i < cycleNodes.size(); i++) {
            cout << cycleNodes[i] << " ";
        }
        cout << cycleNodes[0] << endl;

    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
