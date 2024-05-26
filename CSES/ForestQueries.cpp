// Problem Link: https://cses.fi/problemset/task/1652

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char temp;
            cin >> temp;
            if (temp == '.') {
                forest[i][j] = 0;
            } else {
                forest[i][j] = 1;
            }
        }
    }

    vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefixSum[i][j] = forest[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1]; 
        }
    }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int res = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
        cout << res << endl;
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
