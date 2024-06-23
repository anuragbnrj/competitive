// Problem Link: https://maang.in/problems/Even-and-Odd-Queries-405?resourceUrl=cs78-cp492-pl3320-rs405

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
int INF = 1e9;

struct node {
    int even;
    int odd;
    node (int e = 0, int o = 0) {
        even = e;
        odd = o;
    }
};

node merge(node n1, node n2) {
    return node(n1.even + n2.even, n1.odd + n2.odd);
}

int a[100010];
node segtree[400040];

void build(int idx, int l, int r) {
    if (l == r) {
        if (a[l] % 2 == 0) segtree[idx] = node(1, 0);
        else segtree[idx] = node(0, 1);
        return;
    }

    int mid = l + (r - l) / 2;

    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    segtree[idx] = merge(segtree[2 * idx], segtree[2 * idx + 1]);
}

void update(int idx, int l, int r, int pos, int val) {
    if (pos < l || r < pos) {
        return;
    }

    if (l == r) {
        a[l] = val;
        if (a[l] % 2 == 0) segtree[idx] = node(1, 0);
        else segtree[idx] = node(0, 1);
        return;
    }

    int mid = l + (r - l) / 2;

    update(2 * idx, l, mid, pos, val);
    update(2 * idx + 1, mid + 1, r, pos, val);

    segtree[idx] = merge(segtree[2 * idx], segtree[2 * idx + 1]);
}

node query(int idx, int l, int r, int lq, int rq) {
    if (rq < l || r < lq) {
        return node(0, 0);
    }

    if (lq <= l && r <= rq) {
        return segtree[idx];
    }

    int mid = l + (r - l) / 2;

    return merge(query(2 * idx, l, mid, lq, rq), query(2 * idx + 1, mid + 1, r, lq, rq));
}


void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;

        if (type == 0) {
            int x, y;
            cin >> x >> y;
            x--;

            update(1, 0, n - 1, x, y);
        } else if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--;r--;

            node temp = query(1, 0, n - 1, l, r);
            cout << temp.even << endl;
        } else {
            int l, r;
            cin >> l >> r;
            l--;r--;

            node temp = query(1, 0, n - 1, l, r);
            cout << temp.odd << endl;
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
