// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

bool canPrint(ll toBePrinted, ll mn, ll mx, ll timeAvailable) {
    if (timeAvailable < mn) {
        return false;
    }

    ll currPrinted = 1;
    timeAvailable -= mn;

    ll printedByA = timeAvailable / mn;
    ll printedByB = timeAvailable / mx;

    if (currPrinted + printedByA + printedByB >= toBePrinted) {
        return true;
    }

    return false;
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    ll mn = min(x, y);
    ll mx = max(x, y);

    ll beg = 1;
    ll end = mx * n;

    while (beg < end) {
        ll mid = beg + ((end - beg) / 2);

        if (!canPrint(n, mn, mx, mid)) beg = mid + 1;
        else end = mid; 
    }

    cout << beg << endl;
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
    
    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
