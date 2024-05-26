// Problem Link: https://codeforces.com/problemset/problem/1179/A

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    deque<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> ans(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int fi = a.front();
        a.pop_front();
        int se = a.front();
        a.pop_front();
        ans[i] = {fi, se};

        if (se > fi) {
            swap(fi, se);
        }
        a.push_front(fi);
        a.push_back(se);
    }
    

    while (q--) {
        ll m;
        cin >> m;
        m--;

        if (m < n - 1) {
            cout << ans[m].first << " " << ans[m].second << endl;
        } else {
            int pos = (m - (n - 1)) % (n - 1);
            cout << a.front() << " " << a[pos + 1] << endl;
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

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
