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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> des;
    vector<int> apt;

    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        des.push_back(curr);
    }

    for (int i = 0; i < m; i++) {
        int curr;
        cin >> curr;
        apt.push_back(curr);
    }

    sort(des.begin(), des.end());
    sort(apt.begin(), apt.end());

    int i = 0, j = 0, res = 0;

    while (i < n && j < m) {
        int ll = des[i] - k;
        int ul = des[i] + k;

        if (apt[j] > ul) {
            i++;
        } else if (apt[j] < ll) {
            j++;
        } else {
            i++;
            j++;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
