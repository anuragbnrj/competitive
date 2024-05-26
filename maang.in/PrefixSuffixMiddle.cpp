// Problem Link: https://maang.in/problems/Prefix-Suffix-Middle-424?resourceUrl=cs81-cp495-pl3332-rs424

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;


vector<int> generateKMPArray(string s, int n) {
    vector<int> kmp(n + 1);
    kmp[0] = -1;

    int i = 0, j = -1;
    while(i < n) {
        while (j != -1 && s[i] != s[j]) {
            j = kmp[j];
        }
        j++;
        i++;
        kmp[i] = j;
    }

    return kmp;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> kmp = generateKMPArray(s, n);
    // for (int i = 0; i <= n; i++) {
    //     cout << kmp[i] << " ";
    // }
    // cout << endl;

    int last = kmp[n];

    if (last == 0) {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        if (kmp[i] == last) {
            cout << s.substr(0, last) << endl;
            return;
        }
    }

    if (kmp[last] != 0) {
        cout << s.substr(0, kmp[last]) << endl;
        return;
    }

    cout << -1 << endl;

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
        // cout << endl;
        solve();
    }

    return 0;
}
