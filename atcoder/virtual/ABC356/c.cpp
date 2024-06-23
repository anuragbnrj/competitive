// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
ll INFL = 1e18;
int INF = 1e9;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(m);
    vector<bool> res(m);

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        for (int j = 0; j < c[i]; j++) {
            cin >> a[i][j];
        }
        char ch;
        cin >> ch;
        if (ch == 'o') {
            res[i] = true;
        } else {
            res[i] = false;
        }
    }

    int combinations = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<bool> status(n, false);
        for (int bit = 0; bit < n; bit++) {
            if (mask >> bit & 1 == 1) {
                status[bit] = true;
            }
        }
        
        bool flag = true;
        for (int i = 0; i < m && flag == true; i++) {
            int trueCount = 0;
            for (int j = 0; j < c[i] && flag == true; j++) {
                int key = a[i][j] - 1;

                if (status[key] == true) {
                    trueCount++;
                }
            }

            if (trueCount >= k) {
                if (res[i] == false) {
                    flag = false;
                } 
            } else {
                if (res[i] == true) {
                    flag = false;
                }
            }
        }

        if (flag == true) {
            combinations++;
        }
    }

    cout << combinations << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
