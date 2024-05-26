// Problem Link: https://codeforces.com/contest/433/problem/B

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<ll> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }

    sort(v.begin(), v.end());
    vector<ll> sortedPrefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sortedPrefixSum[i] = sortedPrefixSum[i - 1] + v[i];
    }

    int m; 
    cin >> m;
    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            cout << prefixSum[r] - prefixSum[l - 1] << endl;
        } else {
            cout << sortedPrefixSum[r] - sortedPrefixSum[l - 1] << endl;
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


    solve(); 
    
    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
