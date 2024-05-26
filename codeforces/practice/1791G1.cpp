// Problem Link: https://codeforces.com/problemset/problem/1791/G1

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        a[i] += (i + 1);
    }

    sort(a.begin(), a.end());
    int res = 0, coins = 0;
    for (int i = 0; i < n; i++) {
        if (coins + a[i] > c) {
            break;
        } else {
            coins += a[i];
            res++;
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


    // solve(); 
    
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
