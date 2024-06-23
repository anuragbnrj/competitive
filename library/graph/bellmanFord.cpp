// Problem Link: https://maang.in/problems/BellmanFord-Revisited-209?resourceUrl=cs99-cp522-pl3595-rs209

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
ll INFL = 1e18;
int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> edges[m];
    for (int i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;

        edges[i] = {u, v, -wt};
    }

    vector<ll> dist(n + 1, INFL);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll wt = edges[j][2];

            dist[v] = min(dist[v], dist[u] + wt);
        }
    }

    bool containsCycle = false;
    for (int j = 0; j < m; j++) {
        ll u = edges[j][0];
        ll v = edges[j][1];
        ll wt = edges[j][2];

        if (dist[v] > dist[u] + wt) {
            containsCycle = true;
            break;
        }
    }

    if (containsCycle) {
        cout << "-1" << endl;
    } else {
        cout << -dist[n] << endl;
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
