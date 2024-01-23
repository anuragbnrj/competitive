#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;

    int mx = INT_MIN;
    vector<int> s(n);
    set<int> stt;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        stt.insert(s[i]);
        mx = max(mx, s[i]);
    }

    int bits = 0;
    while (mx > 0) {
        mx = mx >> 1;
        bits++;
    }

    int end = (1 << bits) - 1;

    for (int k = 1; k <= end; k++) {
        int ctr = 0;
        for (int i = 0; i < n; i++) {
            int xr = s[i] ^ k;
            if (stt.count(xr)) {
                ctr++;
            } else {
                break;
            }
        }

        if (ctr == n) {
            cout << k << endl;
            return;
        }
    }

    cout << "-1" << endl;
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
