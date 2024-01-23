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

    vector<int> arr(n);
    vector<int> dep(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cin >> dep[i];
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());


    int i = 0; 
    int j = 0;
    int cus = 0;
    int res = INT_MIN;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            cus++;
            res = max(res, cus);
            i++;
        } else {
            cus--;
            j++;
        }
    }

    cout << res << endl;

    return 0;
}
