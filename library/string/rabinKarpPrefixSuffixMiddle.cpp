// Problem Link: https://codeforces.com/problemset/problem/126/B

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;

vector<ll> h(1000006, 0);

ll prime = 31;

int lengthOfLps(string s) {
    int len = s.size();

    h[0] = s[0] - 'a' + 1;
    for (int i = 1; i < len; i++) {
        int val = s[i] - 'a' + 1;
        h[i] = ((h[i - 1] * prime) % mod + val) % mod; 
    }

    int lenLPS = 0;
    ll primePow = prime;
    for (int i = 0; i < len - 1; i++) {
        ll h1 = h[i];

        ll del = (h[len - 1 - i - 1] * primePow) % mod;
        ll h2 = (((h[len - 1] - del) % mod) + mod) % mod;

        primePow = (primePow * prime) % mod;

        if (h1 == h2) {
            lenLPS = i + 1;
        }
    }

    return lenLPS;
}

bool lpsPresentInString(string s, int len) {
    ll h1 = h[len - 1];

    ll primePow = 1;
    for (int i = 1; i <= len; i++) {
        primePow = (primePow * prime) % mod;
    }
    
    for (int i = 1; i + len - 1 < s.size() - 1; i++) {
        ll h2 = h[i + len - 1];
        ll del = (h[i - 1] * primePow) % mod;

        h2 = (((h2 - del) % mod) + mod) % mod;

        if (h1 == h2) {
            return true;
        }
    }

    return false;
}

void solve() {
    string s;
    cin >> s;

    string notPresent = "Just a legend";

    int lenLps = lengthOfLps(s);

    if (lenLps == 0) {
        cout << notPresent << endl;
    } else {
        bool lpsPresent = lpsPresentInString(s, lenLps);
        string prefix = s.substr(0, lenLps);

        if (lpsPresent) {
            cout << prefix << endl;
        } else {
            int lenLpsPrefix = lengthOfLps(prefix);

            if (lenLpsPrefix == 0 || lenLpsPrefix == (int) prefix.size()) {
                cout << notPresent << endl;
            } else {
                // bool lpsPrefixPresent = lpsPresentInString(prefix, lenLpsPrefix);
                string prefixPrefix = prefix.substr(0, lenLpsPrefix);

                // if (lpsPrefixPresent) {
                //     cout << prefixPrefix << endl;
                // } else {
                //     cout << notPresent << endl;
                // }

                cout << prefixPrefix << endl;
            }
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
