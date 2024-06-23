// Problem Link: https://cses.fi/problemset/task/1661

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<ll, int> freq;
    freq[0] = 1;
    ll curr = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        curr += a[i];
        ll req = curr - x;
        res += freq[req];
        freq[curr]++;
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
