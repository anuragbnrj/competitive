#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007


void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n, 0);
    set<int> used;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        long long temp = a[i];
        int pow = 0;
        while (temp > 0) {
            long long r = temp % k;

            if (!(r == 0 || r == 1)) {
                cout << "NO" << endl;
                return;
            }

            if (r == 1) {
                if (used.count(pow)) {
                    cout << "NO" << endl;
                    return;
                }
                used.insert(pow);
            } 

            pow++;
            temp = temp / k;
        }
    }

    cout << "YES" << endl;
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
