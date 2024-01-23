#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve(int n) {
    if (n == 1) {
        cout << "1" << endl;
        return;
    } else if (n < 4) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    vector<int> res(n, 0);

    int mid = ceil(n / 2.0);

    for (int i = 0, el = mid; i < n; i = i + 2, el--) {
        res[i] = el;
    }

    for (int i = 1, el = n; i < n; i = i + 2, el--) {
        res[i] = el;
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
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

    int n; 
    cin >> n;

    solve(n);   

    return 0;
}
