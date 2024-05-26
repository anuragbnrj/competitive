// Problem Link: https://codeforces.com/problemset/problem/1360/D

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

int len = 1000003;
// spf will store the smallest prime factor of i
// if spf[i] == i, then i is a prime number
vector<int> spf(len + 1); 

void solve() {
    int n, k;
    cin >> n >> k;

    if (k >= n) {
        cout << "1" << endl;
        return;
    }

    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if ((n % i == 0)) {
            int noOfPackages = i; 
            int shovelsPerPackage = n / noOfPackages;
            if (shovelsPerPackage <= k) {
                res = min(res, noOfPackages);
            }

            shovelsPerPackage = i;
            noOfPackages = n / shovelsPerPackage;
            if (shovelsPerPackage <= k) {
                res = min(res, noOfPackages);
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

    // solve(); 

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
