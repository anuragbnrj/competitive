// Problem Link: https://www.codechef.com/practice/course/zco-inoi-problems/ZCOPRAC/problems/ZCO22001

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefixSum[i][j] = grid[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int reqdCount = (c - a + 1) * (d - b + 1);
        int actualCount = prefixSum[c][d] - prefixSum[a - 1][d] - prefixSum[c][b - 1] + prefixSum[a - 1][b - 1];

        if (reqdCount == actualCount) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
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
