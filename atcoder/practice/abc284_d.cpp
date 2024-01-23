// Problem Link: https://atcoder.jp/contests/abc284/tasks/abc284_d 

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

int len = 10000003;
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
void generatePrimes() {
    for (int i = 2; i <= len; i++) {
        if (spf[i] == i) {
            primes.push_back(i);
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    ll temp = n;

    map<ll, int> factors;

    ll a = 0, p, q;
    for (int i = 0; i < primes.size(); i++) {
        if (temp % primes[i] == 0) {
            a = primes[i];
            break;
        }
    }

    if ((temp % (a * a)) == 0) {
        p = a;
        q = temp / (a * a);
    } else {
        q = a;
        p = sqrt((temp / a));
    }

    cout << p << " " << q << endl;
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
    generatePrimes();

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
