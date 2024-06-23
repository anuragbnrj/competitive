// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
int INF = 1e9;

vector<ll> a;
vector<pair<ll, ll>> seg;

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx].first = a[l];
        seg[idx].second = 0;
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    seg[idx].first = seg[2 * idx].first + seg[2 * idx + 1].first;
    seg[idx].second = 0;
}

void update(int idx, int l, int r, int lu, int ru, int u) {
    if (ru < l || r < lu) {
        return;
    }

    if (lu <= l && r <= ru) {
        // seg[idx].first += u;
        seg[idx].second += u;

        return;
    }

    int mid = l + (r - l) / 2;
    update(2 * idx, l, mid, lu, ru, u);
    update(2 * idx + 1, mid + 1, r, lu, ru, u);
}

ll query(int idx, int l, int r, int k, ll updates) {
    if (k < l || r < k) {
        return 0;
    }

    if (l == r) {
        return seg[idx].first + seg[idx].second + updates;
    }

    int mid = l + (r - l) / 2;
    ll res = query(2 * idx, l, mid, k, updates + seg[idx].second) 
    + query(2 * idx + 1, mid + 1, r, k, updates + seg[idx].second);

    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;

    a.resize(n);
    seg.resize(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            ll u;
            cin >> a >> b >> u;

            update(1, 0, n - 1, a - 1, b - 1, u);
        }

        if (type == 2) {
            int k;
            cin >> k;

            ll res = query(1, 0, n - 1, k - 1, 0);
            cout << res << endl;
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
