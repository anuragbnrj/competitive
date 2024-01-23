#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int a, b;
    cin >> a >> b;

    int xr = 0;
    int n = a - 1;
    if (n % 4 == 0) {
        xr = n;
    } else if (n % 4 == 1) {
        xr = 1;
    } else if (n % 4 == 2) {
        xr = n + 1;
    } else {
        xr = 0;
    }

    if (xr == b) {
        cout << a << endl;
        return;
    }

    xr = xr ^ b;

    if (xr == a) {
        cout << a + 2 << endl;
        return;
    }

    cout << a + 1 << endl;

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
