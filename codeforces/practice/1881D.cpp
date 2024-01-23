// Problem Link: https://codeforces.com/contest/1881/problem/D

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> powCtr;
    for (int i = 0; i < n; i++) {
        int temp = a[i];

        while (temp > 1 && spf[temp] != temp) {
            powCtr[spf[temp]]++;
            temp /= spf[temp];
        }

        if (temp > 1) {
            powCtr[temp]++;
        }
    }

    bool flag = true;
    for (auto el : powCtr) {
        if (el.second % n != 0) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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

    // solve(); 

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
