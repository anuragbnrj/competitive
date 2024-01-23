#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    long long n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> freq(31, 0);
    for (int el : a) {
        int temp = el;
        for (int bit = 0; bit < 31; bit++) {
            int last = temp & 1;
            if (last == 1) {
                freq[bit]++;
            }
            temp = temp >> 1;
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < 31; j++) {
            if ((freq[j] % i) != 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            res.push_back(i);
        }
    }

    for (int el : res) {
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

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }   

    return 0;
}
