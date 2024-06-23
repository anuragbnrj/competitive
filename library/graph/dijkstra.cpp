// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
ll INFL = 1e18;
int INF = 1e9;

vector<pair<ll, int>> graph[100005];
ll dist[100005];
int visited[100005];

using state = int;

void dijkstra(state src) {
    priority_queue<pair<ll, state>> pq;
    pq.push({-0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        ll currDist = -top.first;
        state curr = top.second;

        if (visited[curr] != 0) continue;
        visited[curr] = 1;

        for (auto edge : graph[curr]) {
            ll wt = edge.first;
            int neigh = edge.second;
            if (dist[neigh] > currDist + wt) {
                dist[neigh] = currDist + wt;
                pq.push({-dist[neigh], neigh});
            }
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        graph[i] = vector<pair<ll, int>>();
        dist[i] = INFL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
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
