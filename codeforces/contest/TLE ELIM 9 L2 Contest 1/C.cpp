
#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int h, n, m;
    cin >> h >> n >> m;

    while (h > 20 && n > 0) {
        h = (h >> 1) + 10;
        n--;
    }

    while (h > 0 && m > 0) {
        h = h - 10;
        m--;
    }

    if (h > 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}