// Problem Link: https://cses.fi/problemset/task/1646

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> x(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll temp;
        cin >> temp;
        x[i] = x[i - 1] + temp;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << (x[r] - x[l - 1]) << endl;
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
