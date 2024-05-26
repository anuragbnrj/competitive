// Problem Link: https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

bool possible(vector<ll> &x, int c, ll dist) {
    int len = x.size();

    int i = 1;
    c--;
    ll prev = x[0];
    while (c > 0 && i < len) {
        int curr = x[i];
        if (curr - prev >= dist) {
            prev = curr;
            c--;
        }
        i++;
    }

    if (c == 0) {
        return true;
    }
    return false;
}

void solve() {
    int n, c;
    cin >> n >> c;

    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    ll beg = 0;
    ll end = x[n - 1];
    while (beg < end) {
        ll mid = beg + (end - beg) / 2;

        if (possible(x, c, mid)) beg = mid + 1;
        else end = mid;
    }

    cout << beg - 1 << endl;
}  

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
