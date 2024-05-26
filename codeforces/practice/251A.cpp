// Problem Link: https://codeforces.com/problemset/problem/251/A

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n;
    ll d;
    cin >> n >> d;

    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll res = 0;
    for (int i = 0; (i + 2) < n; i++) {
        ll el = x[i] + d;

        int idx = lower_bound(x.begin(), x.end(), el) - x.begin();
        ll totalElements;
        if (idx == n) {
            totalElements = idx - 1 - i;
        } else {
            if (x[idx] <= el) {
                totalElements = idx - i;   
            } else {
                totalElements = idx - 1 - i;
            }
        }

        res += ((totalElements * (totalElements - 1)) / 2); 
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
