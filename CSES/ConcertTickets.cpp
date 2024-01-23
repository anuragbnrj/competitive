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

    int n, m;
    cin >> n >> m;

    multiset<int> prices;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.insert(price);
    }
    // sort(prices.begin(), prices.end());

    vector<int> bid(m);
    for (int i = 0; i < m; i++) {
        cin >> bid[i];
    }

    for (int i = 0; i < m; i++) {
        int curr = bid[i];

        auto ub = prices.upper_bound(curr);

        if (ub == prices.begin()) {
            cout << -1 << endl;
        } else {
            ub--;
            cout << *ub << endl;
            prices.erase(ub);
        }
    }

    return 0;
}
