// Problem Link: https://codeforces.com/problemset/problem/1787/B 

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

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

    // This is to prevent treating 0 and 1 as prime numbers;
    spf[0] = 1;
    spf[1] = 2;
}

void solve() {
    int n, temp;
    cin >> n;
    temp = n;

    map<int, int> mpp;
    int maxPow = 1;
    for (int i = 2; i*i <= temp; i++) {
        if (spf[i] == i) {
            while (temp > 1 && (temp % i == 0)) {
                mpp[i]++;
                temp /= i;
                maxPow = max(maxPow, mpp[i]);
            }
        }
    }
    if (temp > 1) {
        mpp[temp]++;
    }

    ll res = 0;
    int minPow = INT_MAX;
    for (int i = 1; i <= maxPow; i++) {
        int currPr = 1;
        for (auto el : mpp) {
            int a = el.first;
            int p = el.second;

            if (p > 0) {
                currPr *= a;
                mpp[a] = p - 1;
            }

        }
        res += currPr;
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

    // solve();
    generateSmallestPrimeFactors();

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
