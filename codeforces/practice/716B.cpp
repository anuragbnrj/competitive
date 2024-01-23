#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

long long powHelper(int base, int power) {
    if (power == 0) {
        return 1;
    }

    long long ans = powHelper(base, power - 1);
    ans = ans % MOD;
    ans = ans * base;
    ans = ans % MOD;

    return ans;
}

void solve() {
    int n, k;

    cin >> n >> k;

    // long long res = (1LL * n * (n - 1)) % MOD;
    // res = (res * ((long long) pow(2, k - 1) - 1LL)) % MOD;
    // res = (res + (n * 1LL)) % MOD;

    long long ans = powHelper(n, k);

    cout << ans << endl;
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
