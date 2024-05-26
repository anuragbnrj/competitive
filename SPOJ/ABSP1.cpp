// Problem Link: https://www.spoj.com/problems/ABSP1/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // ll restle = 0;
    // for (int i = 0; i < n ;i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         restle += abs(a[i] - a[j]);
    //     }
    // }

    ll curr = 0, prev = 0, res = 0;
    for (int i = 1; i < n; i++) {
        curr = prev + (i) * (a[i] - a[i - 1]);
        res += curr;
        prev = curr;    
    }

    // cout << "----------------" << endl;
    // cout << "restle: " << restle << endl;
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
