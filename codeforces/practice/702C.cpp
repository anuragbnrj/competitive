// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int mxDist = 0;
    for (int i = 0; i < n; i++) {
        int curr = a[i];

        int idx = lower_bound(b.begin(), b.end(), curr) - b.begin();
        if (idx == 0) {
            mxDist = max(mxDist, abs(curr - b[idx]));
        } else if (idx == m) {
            mxDist = max(mxDist, abs(curr - b[m - 1]));
        } else {
            mxDist = max(mxDist, min(abs(curr - b[idx]), abs(curr - b[idx - 1])));
        }
    }

    cout << mxDist << endl;
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
