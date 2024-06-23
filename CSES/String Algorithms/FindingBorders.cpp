// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    ll prime = 31;

    int len = s.size();
    vector<int> prehash(len, 0);

    prehash[0] = s[0] - 'a' + 1;
    for (int i = 1; i < len; i++) {
        int val = s[i] - 'a' + 1;
        prehash[i] = ((prehash[i - 1] * prime) % mod + val) % mod; 
    }

    // for (int i = 0; i < len; i++) {
    //     cout << prehash[i] << "\t"; 
    // }
    // cout << endl;

    ll primePow = prime;
    for (int i = 0; i < len - 1; i++) {
        ll h1 = prehash[i];

        ll del = (prehash[len - 1 - i - 1] * primePow) % mod;
        ll h2 = (((prehash[len - 1] - del) % mod) + mod) % mod;

        primePow = (primePow * prime) % mod;

        // cout << h1 << "\t" << h2 << "\t";

        if (h1 == h2) {
            cout << i + 1 << " ";
        }

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
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
