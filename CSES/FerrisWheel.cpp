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

    int n, x;
    cin >> n >> x;

    vector<int> wt(n);
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    sort(wt.begin(), wt.end());

    int beg = 0, end = n - 1, res = 0;

    while (beg < end) {
        int sum = wt[beg] + wt[end];

        if (sum > x) {
            end--;
            res++;
        } else {
            beg++;
            end--;
            res++;
        }
    }

    if (beg == end) {
        res++;
    }

    cout << res << endl;

    return 0;
}
