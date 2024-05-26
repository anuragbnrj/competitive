// Problem Link: https://maang.in/problems/LR-Sum-Query-18?resourceUrl=cs71-cp481-pl3270-rs18

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1, 0LL);
    for (int i = 1; i < n + 1; i++) {
        ll temp;
        cin >> temp;
        a[i] = a[i - 1] + temp;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << (((a[r] - a[l - 1]) % MOD) + MOD) % MOD << endl;
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
