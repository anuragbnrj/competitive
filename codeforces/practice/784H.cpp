#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> setCount(31, 0);
    for (int i = 0; i < n; i++) {
        for (int bit = 0; bit < 31; bit++) {
            if (a[i] & (1 << bit)) {
                setCount[bit] = setCount[bit] + 1;
            }
        }
    }

    int res = 0;
    for (int i = 30; i >= 0; i--) {
        if (n - setCount[i] <= k) {
            k = k - (n - setCount[i]);
            res = (1 << i) | res;
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

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }   

    return 0;
}
