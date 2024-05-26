// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1000000007;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> freq(26, 0);
    for (char ch : s) {
        freq[ch - 'A']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            oddCount++;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION" << endl;
    } else {
        string f = "", r = "";
        char extra;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq[i] / 2; j++) {
                f += ('A' + i);
                r += ('A' + i);
            }

            if (freq[i] % 2 == 1) {
                extra = ('A' + i);
            }
        }

        reverse(r.begin(), r.end());

        cout << f;
        if (oddCount > 0) {
            cout << extra;
        }
        cout << r << endl;
    }
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
