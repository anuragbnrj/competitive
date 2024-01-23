
#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum = sum + (n % 10);
        n = n / 10;
    }

    return sum;
}

void solve() {
    int k;
    cin >> k;

    int ctr = 0;
    int res;
    for (int i = 19; ; i++) {
        if (sumOfDigits(i) == 10) {
            ctr++;

            if (ctr == k) {
                res = i;
                break;
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

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

    return 0;
}