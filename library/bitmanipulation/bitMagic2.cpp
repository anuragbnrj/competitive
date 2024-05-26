// Problem Link: https://maang.in/problems/Bit-Magic-II-873?resourceUrl=cs99-cp512-pl3482-rs873

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    // 64 bit binary representation
    for (int i = 63; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;

    // Leftmost set bit
    if (n == 0) {
        cout << -1;
    } else {
        cout << (int)__lg(n);
    }
    cout << endl;

    // Rightmost set bit
    if (n == 0) {
        cout << -1;
    } else {
        cout << __builtin_ctzll(n);
    }
    cout << endl;

    // Check power of 2
    int setBits = __builtin_popcountll(n);
    if (n < 2LL || setBits > 1) {
        cout << 0;
    } else {
        cout << 1;
    }
    cout << endl;

    // Biggest power of 2 divisor
    int pwr = __builtin_ctzll(n);
    if (n == 0) {
        cout << -1;
    } else {
        cout << (1LL << pwr);
    }
    cout << endl;

    // Smallest power of 2 which is greater than equal to n
    if (n <= 2LL) {
        cout << 2;
    } else {
        int msb = __lg(n);
        if (__builtin_popcountll(n) == 1) {
            cout << (1LL << msb);
        } else {
            cout << (1LL << (msb + 1));
        }
        // cout << ((1LL << (64 - __builtin_clzll(n - 1))));
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

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
