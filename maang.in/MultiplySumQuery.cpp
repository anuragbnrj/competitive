// Problem Link: https://maang.in/problems/Multiply-Sum-Query-36?resourceUrl=cs71-cp481-pl3270-rs36

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;


void solve() {
    int n, q;
    cin >> n >> q;

    int len = 1000006;
    // int len = 100;
    ll a[len] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll sum[len] = {0};
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= MOD;
    }

    ll mulSum[len] = {0};   
    for (int i = 1; i <= n; i++) {
        mulSum[i] = mulSum[i - 1] + (i * a[i]);
        mulSum[i] %= MOD;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        ll res = mulSum[r] - mulSum[l - 1];
        res = res - ((l - 1) * (sum[r] - sum[l - 1]));
        cout << ((res % MOD) + MOD) % MOD << endl;
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
