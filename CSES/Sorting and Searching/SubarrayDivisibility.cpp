// Problem Link: https://cses.fi/problemset/task/1662

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<ll, int> freq;
    ll currSum = 0;
    ll res = 0;
    freq[0] = 1;
    for (int i = 0; i < n; i++) {
        currSum += a[i];

        ll modulus = ((currSum % n) + n) % n ;

        res += freq[modulus];
        freq[modulus]++;
    }

    cout << res << endl;

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
