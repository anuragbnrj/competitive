#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << m[i][j] << "\t";
    //     }
    //     cout << endl;
    // } 

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int curr = m[i][j];
            
            for (int r = 0; r <= i; r++) {
                for (int c = 0; c <= j; c++) {
                    int comp = m[r][c];
  

                    if (comp > curr) {
                        res++;
                    }
                }
            }
        }
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

    int t;
    cin >> t;

    
	while (t--) {
		solve();
	}  

    return 0;
}
