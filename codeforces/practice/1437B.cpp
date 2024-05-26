// Problem Link: https://codeforces.com/contest/1437/problem/B

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

    int zpair = 0, opair = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '0') {
            zpair++;
        }

        if (s[i] == '1' && s[i + 1] == '1') {
            opair++;
        }
    }

    cout << max(zpair, opair) << endl;

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
