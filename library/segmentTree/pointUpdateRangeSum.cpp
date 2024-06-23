// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
int INF = 1e9;

vector<ll> a;
vector<ll> seg;

void build(int idx, int l, int r) {
    // cout << "l: " << l << ", r: " << r << endl;
    if (l == r) {
        seg[idx] = a[l];
        return;
    }

    int mid = l + ((r - l) / 2);
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

void update(int idx, int l, int r, int pos, ll x) {
    if (pos < l || r < pos) {
        return;
    }
    
    if (l == r) {
        a[pos] = x;
        seg[idx] = x;
        return;
    }

    int mid = l + (r - l) / 2;
    update(2 * idx, l, mid, pos, x);
    update(2 * idx + 1, mid + 1, r, pos, x);
    
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

ll query(int idx, int l, int r, int lq, int rq) {
    if (rq < l || r < lq) {
        // cout << "iter 1: " << l << " " << r << " " << lq << " " << rq << " " << 0 << endl;
        return 0LL;
    }

    if (lq <= l && r <= rq) {
        // cout << "iter 2: " << l << " " << r << " " << lq << " " << rq << " " << seg[idx] << endl;
        return seg[idx];
    }

    int mid = l + (r - l) / 2;
    ll res = query(idx * 2, l, mid, lq, rq) + query(idx * 2 + 1, mid + 1, r, lq, rq);
    // cout << "iter 3: " << l << " " << r << " " << lq << " " << rq << " " << res << endl;

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
    // for (int i = 0; i < seg.size(); i++) {
    //     cout << i << ": " << seg[i] << endl;
    // }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int i;
            ll x;
            cin >> i >> x;

            update(1, 0, n - 1, i - 1, x);
        }

        if (type == 2) {
            int lq, rq;
            cin >> lq >> rq;

            int res = query(1, 0, n - 1, lq - 1, rq - 1);
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
