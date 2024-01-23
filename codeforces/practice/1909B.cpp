// Problem Link: https://codeforces.com/problemset/problem/1909/B

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll div = 1;
    bool flag = true;
    do {
        div = div * 2;
        for (int i = 1; i < n; i++) {
            if ((a[i] % div) != (a[i - 1] % div)) {
                cout << div << endl;
                flag = false;
                break;
            }
        }
    } while(flag);


}  

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // solve(); 

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
