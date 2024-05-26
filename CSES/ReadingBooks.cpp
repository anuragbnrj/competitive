// Problem Link: https://cses.fi/problemset/task/1631 

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<ll> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());

    ll sumFirst = t[0], sumElse = 0LL; 
    for (int i = 1; i < n; i++) {
        sumElse += t[i];
    }

    if (sumFirst > sumElse) {
        cout << 2 * sumFirst << endl;
    } else {
        cout << sumFirst + sumElse << endl;
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

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
