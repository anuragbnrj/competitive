#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007


void solve() {
    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << "No" << endl;
        return;
    }

    if (n % 2 == 1) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n - 1; i++) {
            cout << "1\t";
        }
        cout << m - (n - 1) << endl;
    } else {
        if (m % 2 == 1) {
            cout << "No" << endl;
            return;
        } else {
            cout << "Yes" << endl;
            for (int i = 1; i <= n - 2; i++) {
                cout << "1\t";
            }

            int rem = m - (n - 2);
            cout << rem / 2 << "\t" << rem / 2 << endl;
        }
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
