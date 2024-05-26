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

bool cycleExists = false;

vector<int> dfs(int node, int prev) {
    // parent[node] = prev;
    color[node] = 2;

    int cyclesize = 0;
    for (int neigh : graph[node]) {
        if (color[neigh] == 1) {
            dfs(neigh, node);
        } else if (color[neigh] == 2 && neigh != prev) {
            // int curr = node;
            // while (curr != neigh) {
            //     cyclesize++;
            //     curr = parent[curr];
            // }
            // cyclesize++;

            // if (cyclesize >= 4) {
            //     cycleExists = true;
            // }
        } 
    }

    color[node] = 3;
}

void solve() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    color.assign(n + 1, 1);
    parent.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) {
            dfs(i, 0);
        }
    }

    if (cycleExists) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
