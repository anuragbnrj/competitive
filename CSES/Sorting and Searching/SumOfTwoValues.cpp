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

    int n, x;
    cin >> n >> x;

    bool flag = false;
    int p1, p2;

    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;

        int req = x - curr;

        if (mpp.count(req)) {
            p1 = mpp[req];
            p2 = i;
            flag = true;
        } 

        mpp[curr] = i;
    }

    if (flag) {
        cout << p1 + 1 << " " << p2 + 1 << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
