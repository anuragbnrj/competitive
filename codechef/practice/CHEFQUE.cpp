
#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    long long q, s, a, b, res = 0LL;
    cin >> q >> s >> a >> b;
    vector<int> bitCount(64, 0);
    
    while (q--) {
        long long temp = s >> 1;
        int contains = true;
        for (int bit = 0; bit < 64; bit++) {
            if ((temp >> bit & 1)) {
                if (bitCount[bit] < 1) {
                    contains = false;
                    break;
                }
            } 
        }

        if ((s & 1) && !contains) {
            for (int bit = 0; bit < 64; bit++) {
                if ((temp >> bit & 1)) {
                    bitCount[bit] += 1; 
                }
            }
        }
        
        if (!(s & 1) && contains) {
            for (int bit = 0; bit < 64; bit++) {
                if ((temp >> bit & 1)) {
                    bitCount[bit] -= 1; 
                }
            }
        }
        
        

        s = (s * a + b) % ((int) pow(2, 32));
        
    }

    for (int bit = 0; bit < 64; bit++) {
        res = res + (bitCount[bit] * pow(2, bit));
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
    
    solve();

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}