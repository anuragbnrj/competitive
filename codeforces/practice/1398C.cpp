// Problem Link: https://codeforces.com/contest/1398/problem/C

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> psum(n + 1, 0);
    unordered_map<int, int> freq;
    freq[0]++;
    for (int i = 1; i <= n; i++) {
        char ch = s[i - 1];
        int temp = ch - '0';

        psum[i] = psum[i - 1] + temp;

        freq[psum[i] - i]++;
    }

    ll res = 0;
    for (auto el : freq) {
        res += ((1LL * el.second * (el.second - 1)) / 2);
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


    // solve(); 
    
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
