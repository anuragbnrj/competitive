// Problem Link: https://codeforces.com/problemset/problem/1305/C 

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n > m) {
        cout << 0 << endl;
        return;
    }

    long long res = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            res = ((res%m) * (abs(a[i] - a[j])%m)) % m;
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

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
