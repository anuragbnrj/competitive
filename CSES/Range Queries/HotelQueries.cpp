// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
int INF = 1e9;

vector<int> h;
vector<int> seg;

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = h[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * idx, l , mid);
    build(2 * idx + 1, mid + 1, r);

    seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
}

void update(int idx, int l, int r, int pos, int val) {
    if (pos < l || r < pos) {
        return;
    }

    if (l == r) {
        seg[idx] = val;
        h[pos] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    update(2 * idx, l, mid, pos, val);
    update(2 * idx + 1, mid + 1, r, pos, val);

    seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
}

pair<bool, int> query(int idx, int l, int r, int val) {
    if (seg[idx] < val) {
        return {false, -1};
    }

    if (l == r) {
        if (h[l] < val) {
            return {false, -1};
        } else {
            return {true, l};
        }
    }

    int mid = l + (r - l) / 2;

    auto left = query(2 * idx, l, mid, val);
    if (left.first) {
        return left;
    }

    auto right = query(2 * idx + 1, mid + 1, r, val);
    return right;
}

void solve() {
    int n, m;
    cin >> n >> m;

    h.resize(n);
    seg.resize(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    build(1, 0, n - 1);

    vector<int> r(m);
    vector<int> res;
    for (int i = 0; i < m; i++) {
        cin >> r[i];

        auto possible = query(1, 0, n - 1, r[i]);

        if (possible.first) {
            res.push_back(possible.second + 1);

            update(1, 0, n - 1, possible.second, h[possible.second] - r[i]);
        } else {
            res.push_back(0);
        }
    }

    

    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
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
