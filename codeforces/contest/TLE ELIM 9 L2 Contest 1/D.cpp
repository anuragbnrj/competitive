#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    int ctr = 1;
    int idx = 0;
    for (int i = 1; i < 2*n; i++) {
        if (a[i] >= a[i - 1]) {
            ctr++;
        } else {
            ctr = 1;
            idx = i;
        }

        if (ctr == n) {
            break;
        }
    }

    // if (n == 99998 && a[0] == 99997) {
    //     cout << "HELLO: " << a[n - 1] << "\t" << a[2*n - 1] << endl; 
    // }
    

    if (ctr == n) {
        int res = idx == 0 ? 0 : (n - idx);
        cout << res << endl;
    } else {
        cout << "-1" << endl;
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

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

    return 0;
}
