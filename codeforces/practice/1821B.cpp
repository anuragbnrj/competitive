// Problem Link: https://codeforces.com/contest/1821/problem/B

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int beg = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            beg = i;
            break;
        }
    }
    while(beg > 0 && b[beg - 1] <= b[beg]) {
        beg--;
    }

    int end = n - 1;
    for (int i = end; i >= 0; i--) {
        if (a[i] != b[i]) {
            end = i;
            break;
        }
    }
    while (end < (n - 1) && b[end] <= b[end + 1]) {
        end++;
    }
    

    cout << beg + 1 << " " << end + 1 << endl;
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
