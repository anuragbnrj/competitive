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

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long res = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            res = (res + (arr[i - 1] - arr[i]));

            arr[i] = arr[i - 1];
        }
    }

    cout << res << endl;

    return 0;
}
