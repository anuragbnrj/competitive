// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;

ll getHash(string s, ll prime) {
    int n = s.size();

    ll hash = 0;
    for (int i = 0; i < n; i++) {
        int val = s[i] - 'a' + 1;
        hash = (hash * prime + val) % mod;
    }

    return hash;
}

vector<int> rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    ll prime = 103;
    ll primePow = 1;
    for (int i = 0; i < m - 1; i++) {
        primePow = (primePow * prime) % mod;
    }

    vector<int> matches;
    
    ll hpattern = getHash(pattern, prime);
    ll htext = getHash(text.substr(0, m), prime);

    if (htext == hpattern) {
        matches.push_back(0);
    }

    for (int beg = 1, end = m; end < n; beg++, end++) {
        ll del = ((text[beg - 1] - 'a' + 1) * primePow) % mod;
        ll add = text[end] - 'a' + 1;

        htext = ((htext - del + mod) * prime + add) % mod;

        if (htext == hpattern) {
            matches.push_back(beg);
        }
    }

    return matches;
}

void solve() {
    int n;
    cin >> n;

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
