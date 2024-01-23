#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define mod 1000000007


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

    vector<pair<int, int>> mov;
    for (int i = 0; i < n; i++) {
        int st, fi;
        cin >> st >> fi;
        mov.push_back(make_pair(fi, st));
    }
    sort(mov.begin(), mov.end());

    int tot = 0;
    int lastFi = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (mov[i].second >= lastFi) {
            tot++;
            lastFi = mov[i].first;
        }
    }

    cout << tot << endl;
    

    return 0;
}
