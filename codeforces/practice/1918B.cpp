// Problem Link: https://codeforces.com/contest/1918/problem/B

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int,int>> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = {a[i], b[i]};
    }
    sort(c.begin(), c.end());

    for (int i = 0; i < n; i++) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

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
