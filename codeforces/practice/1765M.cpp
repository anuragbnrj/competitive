// Problem Link: https://codeforces.com/contest/1765/problem/M

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    ll res = LLONG_MAX;
    int fina, finb;
    // cout << "----------------------\n";
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int a = i;
            int b = n - a;
            ll temp = lcm(a, b);
            if (temp < res) {
                res = temp;
                fina = a;
                finb = b;
            }

            if (i != 1) {
                a = n / i;
                b = n - a;
                temp = lcm(a, b);
                if (temp < res) {
                    res = temp;
                    fina = a;
                    finb = b;
                }
            }
        }
        

    }

    cout << fina << " " << finb << endl;
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
