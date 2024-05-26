// Problem Link: https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

ll binaryToGrey(ll binary) {
    return binary ^ (binary >> 1);
}

ll convertToBinary(int n) {
    ll binary = 0;
    int pwr = 0;
    while (n > 0) {
        ll rem = n % 2;
        n /= 2;
        binary = binary + pow(10, pwr) * rem;
        pwr++;
    }

    return binary;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        // ll binary = convertToBinary(i);
        // cout << binary << endl;
        ll grey = binaryToGrey(i);
        ll binary = convertToBinary(grey);

        string temp = to_string(binary);
        while ((int)temp.size() < n) {
            temp = '0' + temp;
        }

        cout << temp << endl;
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
