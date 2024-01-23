
#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    cout << a[0] << endl;
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