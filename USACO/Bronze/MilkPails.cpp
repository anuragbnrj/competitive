
#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve(int x, int y, int m) {
    int l1 = m / x;
    int l2 = m / y;

    int mxVal = 0;

    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            int val = i * x + j * y;

            if (val <= m) {
                mxVal = max(mxVal, val);
            }
        }
    }

    cout << mxVal << endl;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y, m; 
    cin >> x >> y >> m;   

    solve(x, y, m);

    return 0;
}
