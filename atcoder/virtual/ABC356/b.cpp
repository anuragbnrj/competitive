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
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<int> tot(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;

            tot[j] += temp;
        }
    }

    bool flag = true;
    for (int i = 0; i < m; i++) {
        if (a[i] > tot[i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
