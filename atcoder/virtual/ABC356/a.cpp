// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
ll INFL = 1e18;
int INF = 1e9;


void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 1; i < l; i++) {
        cout << i << " ";
    }

    for (int i = r; i >= l; i--) {
        cout << i << " ";
    }

    for (int i = r + 1; i <= n; i++) {
        cout << i << " ";
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
