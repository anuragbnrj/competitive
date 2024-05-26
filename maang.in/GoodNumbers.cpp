// Problem Link: https://maang.in/problems/Good-Numbers-23?resourceUrl=cs71-cp481-pl3270-rs23

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;


void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    int len = 1000006;
    
    int a[len] = {0};
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        a[l]++;
        a[r + 1]--;
    }

    for (int i = 1; i < len; i++) {
        a[i] = a[i - 1] + a[i];
    }

    for (int i = 1; i < len; i++) {
        if (a[i] >= k) {
            a[i] = a[i - 1] + 1;
        } else {
            a[i] = a[i - 1];
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (a[r] - a[l - 1]) << endl;
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
