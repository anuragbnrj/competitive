// Problem Link: https://codeforces.com/problemset/problem/1671/D

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    int mn = INT_MAX;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    ll sum = 0;
    for (int i = 1; i < n; i++) {
        sum += abs(a[i] - a[i - 1]);
    }

    if (1 < mn) {
        ll temp = sum + min(abs(a[0] - 1), abs(a[n - 1] - 1));
        for (int i = 1; i < n; i++) {
            temp = min(temp, sum - abs(a[i] - a[i - 1]) + abs(a[i - 1] - 1) + abs(a[i] - 1));
        }

        sum = temp;
    }

    if (mx < x) {
        ll temp = sum + min(abs(a[0] - x), abs(a[n - 1] - x));
        for (int i = 1; i < n; i++) {
            temp = min(temp, sum - abs(a[i] - a[i - 1]) + abs(a[i - 1] - x) + abs(a[i] - x));
        }

        sum = temp; 
    }

    cout << sum << endl;
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
