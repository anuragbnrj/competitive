// Problem Link: https://maang.in/problems/Shortest-Path-II-208?resourceUrl=cs99-cp522-pl3596-rs208

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
ll INFL = 1e18;
int INF = 1e9;

ll dist[505][505];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) dist[i][j] = INFL;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (dist[a][b] != INFL) {
            cout << dist[a][b] << endl;
        } else {
            cout << "-1" << endl;
        }
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
