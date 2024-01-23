// Problem Link: https://codeforces.com/contest/26/problem/A

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

vector<int> smallestPrimeFactors(int n) {

    // spf will store the smallest prime factor of i
    // if spf[i] == i, then i is a prime number
    vector<int> spf(n + 1); 

    // fills the vector with values starting from 0. Eg: 0, 1, 2, 3, ...
    iota(spf.begin(), spf.end(), 0);

    for (int i = 2; i*i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i*i ; j <= n; j = j + i) {
                if (spf[j] == j) {
                    spf[j] = i; 
                }
            }
        }
    }

    return spf;
}

void solve() {
    int n;
    cin >> n;

    vector<int> spf = smallestPrimeFactors(n);

    int res = 0;

    for (int i = 2; i <= n; i++) {
        unordered_set<int> primeFactors;
        int temp = i;
        while (temp > 1) {
            primeFactors.insert(spf[temp]);
            temp /= spf[temp];
        }

        if (primeFactors.size() == 2) {
            res++;
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

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}

