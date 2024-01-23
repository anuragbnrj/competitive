// Problem Link: https://codeforces.com/contest/271/problem/B

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


vector<int> nearestGreaterPrime(len + 1);
void generateNearestGreaterPrimes() {
    int prime = 100003;

    for (int i = 100002; i >= 1; i--) {
        if (spf[i] == i) {
            prime = i;
        }

        nearestGreaterPrime[i] = prime;
    }

    nearestGreaterPrime[1] = 2;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int diff[n][m];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int temp;
            cin >> temp;

            diff[r][c] = (nearestGreaterPrime[temp] - temp);
        }
    }

    int res = INT_MAX;
    for (int r = 0; r < n; r++) {
        int sum = 0;
        for (int c = 0; c < m; c++) {
            sum += diff[r][c];
        }
        res = min(res, sum);
    }

    for (int c = 0; c < m; c++) {
        int sum = 0;
        for (int r = 0; r < n; r++) {
            sum += diff[r][c];
        }
        res = min(res, sum);
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

    generateSmallestPrimeFactors();
    generateNearestGreaterPrimes();

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
