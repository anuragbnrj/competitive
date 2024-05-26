// Problem Link: https://codeforces.com/contest/1201/problem/C

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

bool isMedianPossible(vector<int> &a, ll moves, ll target, int n) {
    int medIdx = n / 2;

    ll movesReqd = 0;
    for (int i = medIdx; i < n; i++) {
        if(a[i] <= target) {
            movesReqd += (target - a[i]);
        } else {
            break;
        }
    }

    if (movesReqd <= moves) {
        return true;
    }

    return false;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int medIdx = n / 2;
    ll median = a[medIdx];

    ll beg = median;
    ll end = 3000000009;

    while (beg < end) {
        int mid = beg + ((end - beg) / 2);

        if (isMedianPossible(a, k, mid, n)) beg = mid + 1;
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


    solve(); 
    
    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
