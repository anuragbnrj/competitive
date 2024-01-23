// Problem Link: https://codeforces.com/contest/1855/problem/B

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

void solve() {
    ll n, temp;
    cin >> n;
    temp = n;

    vector<ll> divisors;
    divisors.push_back(1);
    if (temp != 1) { 
        divisors.push_back(temp); 
    }
    unordered_set<ll> divisorsSet;
    for (ll i = 2; i*i <= min(100005LL, temp); i++) {
        if (temp % i == 0) {
            // divisors.push_back(i);
            // divisors.push_back(temp / i);
            divisorsSet.insert(i);
            divisorsSet.insert(temp / i);
        }
    }
    // for (int i = 0; i < (int)primes.size(); i++) {
    //     while(temp > 1 && (temp % primes[i] == 0)) {
    //         temp /= primes[i];
    //         divisors.push_back(primes[i]);
    //         divisors.push_back(temp);
    //     }
    // }

    for (auto el : divisorsSet) {
        divisors.push_back(el);
    }

    sort(divisors.begin(), divisors.end());

    

    ll res = 1, currLen = 1;
    for (int i = 1; i < (int) divisors.size(); i++) {
        if (divisors[i] == (divisors[i - 1] + 1)) {
            currLen++;
            res = max(res, currLen);
        } else {
            currLen = 1;
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

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
