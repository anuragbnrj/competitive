// Problem Link: https://www.spoj.com/problems/PERIOD/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;



vector<int> generateKMPArray(string s, int len) {
    vector<int> kmp(len + 1);
    kmp[0] = -1;

    int i = 0, j = -1;
    while (i < len) {
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

    for (int i = 2; i <= n; i++) {
        if (kmp[i] != 0 && ((i % (i - kmp[i])) == 0)) {
            cout << i << " " << (i / (i - kmp[i])) << endl;
        }
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


    // solve(); 
    
    int t, c = 1; 
    cin >> t;
    while (t--) {
        cout << "Test case #" << c << endl;
        solve();
        
        c++;
    }

    return 0;
}
