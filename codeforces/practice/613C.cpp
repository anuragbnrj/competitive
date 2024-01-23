// Problem Link: https://codeforces.com/problemset/problem/1285/C

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

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

vector<int> primes;
void getPrimes() {
    for (int i = 2; i <= len; i++) {
        if (spf[i] == i) {
            primes.push_back(i);
        }
    }
}

ll res1 = LLONG_MAX, res2 = LLONG_MAX;
void f(int idx, vector<ll> &factors, ll a, ll b) {
    if (idx == factors.size()) {
        ll mx = max(a, b);
        if (mx < max(res1, res2)) {
            res1 = min(a, b);
            res2 = max(a, b);
        }
        return;
    }

    
    f(idx + 1, factors, a * factors[idx], b);
    f(idx + 1, factors, a, b * factors[idx]);
}

void solve() {
    ll x;
    cin >> x;

    ll temp = x, pr = 1, mx = 1, res = LLONG_MAX, a, b;
    vector<ll> factors;
    for (int i = 0; i < (int)primes.size(); i++) {
        ll facPr = 1;
        bool flag = false;
        while (temp > 1 && (temp % primes[i] == 0)) {
            flag = true;
            facPr *= primes[i];
            temp /= primes[i];
        }
        if (flag) {
            factors.push_back(facPr);
        }
    }

    if (temp > 1) {
        factors.push_back(temp);
    }

    f(0, factors, 1, 1);

    cout << res1 << " " << res2 << endl;

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
    getPrimes();

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
