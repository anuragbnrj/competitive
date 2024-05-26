// Problem Link: https://atcoder.jp/contests/abc119/tasks/abc119_d

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int a, b, q;
    cin >> a >> b >> q;

    vector<ll> s(a);
    for (int i = 0; i < a; i++) {
        cin >> s[i];
    }

    vector<ll> t(b);
    for (int i = 0; i < b; i++) {
        cin >> t[i];
    }

    while (q--) {
        ll x;
        cin >> x;

        int lbs = lower_bound(s.begin(), s.end(), x) - s.begin();
        ll sl, sr;
        if (lbs == 0) {
            sl = -100000000001;
            sr = s[lbs];
        } else if (0 < lbs && lbs < a) {
            sl = s[lbs - 1];
            sr = s[lbs];
        } else {
            sl = s[lbs - 1];
            sr = 100000000001;
        }

        int lbt = lower_bound(t.begin(), t.end(), x) - t.begin();
        ll tl, tr;
        if (lbt == 0) {
            tl = -100000000001;
            tr = t[lbt];
        } else if (0 < lbt && lbt < b) {
            tl = t[lbt - 1];
            tr = t[lbt];
        } else {
            tl = t[lbt - 1];
            tr = 100000000001;
        }

        ll res = max(tr - x, sr - x);
        res = min(res, max(x - sl, x - tl));
        res = min(res, (x - sl) * 2 + (tr - x));
        res = min(res, (x - tl) * 2 + (sr - x));
        res = min(res, (x - sl) + (tr - x) * 2);
        res = min(res, (x - tl) + (sr - x) * 2);

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


    solve(); 
    
    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
