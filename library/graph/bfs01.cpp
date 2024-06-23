// Problem Link: https://maang.in/problems/Edge-Reverse-900?resourceUrl=cs99-cp522-pl3553-rs900

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
int INF = 1e9;

vector<vector<pair<int, int>>> graph;
vector<int> visited;
vector<int> dist;

void solve() {
    int n, m;
    cin >> n >> m;
    
    graph.clear();
    graph.resize(n + 1);
    visited.clear();
    visited.assign(n + 1, 0);
    dist.clear();
    dist.assign(n + 1, INF);
    while (m--) {
        int x, y;
        cin >> x >> y;

        if (x == y) continue;

        graph[x].push_back({0, y});
        graph[y].push_back({1, x});
    }

    
    deque<int> dq;
    dq.push_front(1);
    dist[1] = 0;

    while (dq.size() > 0) {
        int front = dq.front();
        dq.pop_front();

        if (visited[front] == 1) continue;
        visited[front] = 1;

        for (auto edge : graph[front]) {
            int weight = edge.first;
            int node = edge.second;

            if (dist[front] + weight < dist[node]) {
                dist[node] = dist[front] + weight;

                if (weight == 0) {
                    dq.push_front(node);
                } else {
                    dq.push_back(node);
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << dist[i] << "\t";
    // }
    // cout << endl;

    if (dist[n] == INF) {
        cout << "-1" << endl;
    } else {
        cout << dist[n] << endl;
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
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
