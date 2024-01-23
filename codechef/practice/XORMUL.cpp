#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    
    int abit = 0, bbit = 0;
    int res = 0;
    for (int bit = 0; bit < n; bit++) {
        abit = a & (1);
        bbit = b & (1);
        
        if (abit == bbit) {
            res = res | ((1 - abit) << bit);
        } else {
            res = res | (abit << bit);
        }

        a = a >> 1;
        b = b >> 1;
        
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
