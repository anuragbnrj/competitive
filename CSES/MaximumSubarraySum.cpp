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

    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long res = arr[0];
    long long curr = arr[0];

    for (int i = 1; i < n; i++) {
        curr = max(arr[i], curr + arr[i]);
        res = max(res, curr);
    }

    cout << res << endl;

    return 0;
}
