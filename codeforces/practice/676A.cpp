#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int a, b;
    cin >> a >> b;

    int x = a & b;

    int minXr = (a ^ x) + (b ^ x);
    cout << minXr << endl;
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
