#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q; 
    cin >> n >> q;

    string s;
    cin >> s;

    s = " " + s;
    int len = s.size();
    int temp = 0;
    vector<int> csum(len + 1, 0);

    for (int i = 1; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            temp++;
        }

        csum[i] = temp;
    }

    csum[len] = temp;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        cout << csum[r - 1] - csum[l - 1] << endl;
    }

    return 0;
}
