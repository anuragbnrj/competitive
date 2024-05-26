// Problem Link: https://codeforces.com/contest/276/problem/C

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> freq(n + 1, 0);
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        freq[l]++;

        if (r < n) {
            freq[r + 1]--;
        }
    }

    for (int i = 1; i < n + 1; i++) {
        freq[i] += freq[i - 1]; 
    }
    sort(freq.begin(), freq.end());

    ll res = 0;
    for (int i = 1; i < n + 1; i++) {
        res += (freq[i] * a[i]);
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


    solve(); 
    
    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
