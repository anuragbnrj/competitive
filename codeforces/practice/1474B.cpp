// Problem Link: https://codeforces.com/problemset/problem/1474/B

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

int len = 1000003;
// spf will store the smallest prime factor of i
// if spf[i] == i, then i is a prime number
vector<int> spf(len + 1); 

void generateSmallestPrimeFactors() {
    // fills the vector with values starting from 0. Eg: 0, 1, 2, 3, ...
    iota(spf.begin(), spf.end(), 0);

    for (int i = 2; i*i <= len; i++) { // O(N log log N)
        if (spf[i] == i) {
            for (int j = i*i ; j <= len; j = j + i) {
                if (spf[j] == j) {
                    spf[j] = i; 
                }
            }
        }
    }

    // This is to prevent treating 0 and 1 as prime numbers;
    spf[0] = 1;
    spf[1] = 2;

}  

void solve() {
    int d;
    cin >> d;

    int prime1, prime2;
    for (int i = 1 + d; i < len; i++) {
        if (spf[i] == i) {
            prime1 = i;
            break;
        }
    }

    for (int i = prime1 + d; i < len; i++) {
        if (spf[i] == i) {
            prime2 = i;
            break;
        }
    }

    cout << prime1 * prime2 << endl;
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
    generateSmallestPrimeFactors();

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
