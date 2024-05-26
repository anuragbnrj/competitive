// Problem Link: https://cses.fi/problemset/task/1620

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

bool feasible(int n, vector<ll> &k, ll mid, int t) {
    ll products = 0;
    for (int i = 0; i < n; i++) {
        products += (mid / k[i]);

        // Need to break if number of products >= t to prevent overflow even in long long data type
        if (products >= t) {
            return true;
        }
    }

    return false;
}


void solve() {
    int n, t;
    cin >> n >> t;

    vector<ll> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    ll start = 0;
    ll end = 1e18;
    while (start < end) {
        ll mid = start + (end - start) / 2;
        if (!feasible(n, k, mid, t)) start = mid + 1;
        else end = mid;
    }
    
    cout << start << endl;
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

    return 0;
}
