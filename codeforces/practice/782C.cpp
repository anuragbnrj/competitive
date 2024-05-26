// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;
double eps = 0.000000000001;

bool check(vector<int> &x, vector<int> &v, double mid) {
    double overlap;

    double lmax = DBL_MIN;
    double rmin = DBL_MAX;
    for (int i = 0; i < x.size(); i++) {
        double lcurr = x[i] - (mid * v[i]);
        double rcurr = x[i] + (mid * v[i]);

        lmax = max(lmax, lcurr);
        rmin = min(rmin, rcurr);
    }

    // cout << mid << ", " << lmax << ", " << rmin << endl;
    overlap = (rmin - lmax);

    if (overlap >= 0.0) {
        return true;
    } else {
        return false;
    }

}

void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    double beg = 0;
    double end = 1e9;

    int iter = 100;
    while(iter--) {
        double mid = beg + (end - beg) / 2;

        // cout << mid << endl;

        if (!check(x, v, mid)) beg = mid + eps;
        else end = mid;
    }

    cout << fixed << setprecision(12) << beg << endl;
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
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
