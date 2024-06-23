// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;

long double PI = acos(-1.0);
ll MOD = 998244353;
ll INFL = 1e18;
int INF = 1e9;

// Number of set bits at ith position in the interval [0, x]
long long setBitsAtIdx(int i, long long x) {
    long long totalNumbersPresent = (x + 1);
    long long boxsize = (1LL << (i + 1));

    long long fullboxes = totalNumbersPresent / boxsize;
    long long ans = fullboxes * (1LL << i);

    long long extra = totalNumbersPresent % boxsize;
    ans += max(extra - (1LL << i), 0LL);
    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll res = 0;
    for (int bit = 0; bit < 60; bit++) {
        if (((m >> bit) & 1) == 1) {
            ll setBits = setBitsAtIdx(bit, n);
            res = (res + setBits) % MOD;
        }
    }

    cout << res << endl;
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
