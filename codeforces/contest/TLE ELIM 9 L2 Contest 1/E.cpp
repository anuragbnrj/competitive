// Problem Link: https://codeforces.com/group/Is2YXwUuFr/contest/497810/problem/E

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int minAnd = a[0];
    for (int i = 1; i < n; i++) {
        minAnd = minAnd & a[i];
    }

    if (minAnd > 0) {
        cout << "1" << endl;
    } else {
        bool reset = true;
        int andd = 0;
        int ctr = 0;
        for (int i = 0; i < n; i++) {
            if (reset) {
                andd = a[i];
                reset = false;
            } else {
                andd = andd & a[i];
            }

            if (andd == minAnd) {
                reset = true;
                ctr++;
            }
        }

        cout << ctr << endl;
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

    // solve(); 

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
