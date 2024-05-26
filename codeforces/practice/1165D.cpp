// Problem Link: https://codeforces.com/problemset/problem/1165/D

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    sort(d.begin(), d.end());

    ll res = d[0] * d[n - 1];
    vector<ll> dd;
    for (ll div = 2; div * div <= res; div++) {
        if (res % div == 0) {
            if (res / div == div) {
                dd.push_back(div);
            } else {
                dd.push_back(div);
                dd.push_back(res / div);
            }
        }
    }
    sort(dd.begin(), dd.end());

    if (d == dd) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
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

    // solve();

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
