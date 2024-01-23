// Problem Link: https://codeforces.com/problemset/problem/797/A

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

int len = 100003;
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
} 

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> factors;
    int temp = n;
    while (temp > 1) {
        factors.push_back(spf[temp]);
        temp = temp / spf[temp];
    }

    if (factors.size() < k) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < k - 1; i++) {
            cout << factors[i] << " ";
        }

        int pr = 1;
        for (int i = k - 1; i < factors.size(); i++) {
            pr = pr * factors[i];
        }
        cout << pr << endl;
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

    generateSmallestPrimeFactors();

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
