#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int n, k;
    cin >> n >> k;

    if (k < __builtin_popcount(n) || k > n) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<int> ones;
    vector<int> others;
    int temp = n, bit = 0;
    while (bit < 31) {
        if (temp & (1 << bit)) {
            if ((1 << bit) == 1) {
                ones.push_back(1);
            } else {
                others.push_back((1 << bit));
            }
        }

        bit++;
    }

    while ((ones.size() + others.size()) < k) {
        int back = others.back();
        others.pop_back();

        if ((back >> 1) == 1) {
            ones.push_back(1);
            ones.push_back(1);
        } else {
            others.push_back(back >> 1);
            others.push_back(back >> 1);
        }
    }

    for (int el : others) {
        cout << el << "\t";
    }
    for (int el : ones) {
        cout << el << "\t";
    }
    cout << endl;
}  

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }   

    solve();

    return 0;
}
