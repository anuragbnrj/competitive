// Problem Link: https://maang.in/problems/Bit-Magic-I-884?resourceUrl=cs99-cp512-pl3482-rs884

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;

void solve() {
    int q;
    cin >> q;

    ll num = 0;
    while (q--) {
        int t, i;
        cin >> t;

        if (t == 1) {
            cin >> i;
            cout << ((num >> i) & 1) << endl;
        } 
        
        if (t == 2) {
            cin >> i;
            num = num | (1LL << i);
        }
        
        if (t == 3) {
            cin >> i;
            num = num & ~(1LL << i);
        }

        if (t == 4) {
            cin >> i;
            num = num ^ (1LL << i);
        }

        if (t == 5) {
            if (__builtin_popcountll(num) == 60) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }

        if (t == 6) {
            if (num > 0LL) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }

        if (t == 7) {
            if (num == 0LL) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }

        if (t == 8) {
            cout << (__builtin_popcountll(num)) << endl;
        }

        if (t == 9) {
            cout << num << endl;
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
    
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
