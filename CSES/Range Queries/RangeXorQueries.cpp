// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
int INF = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    vector<int> xrsum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xrsum[i] = xrsum[i - 1] ^ a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        // l--;
        // r--;
        int res = xrsum[r] ^ xrsum[l - 1];
        cout << res << endl;
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
