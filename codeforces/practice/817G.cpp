#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int n;
    scanf("%d", &n);

    vector<int> arr;
    int xr = 0;
    for (int i = 0; i <= n - 3; i++) {
        xr = xr ^ i;
        arr.push_back(i);
    }

    if (xr == 0) {
        arr.erase(arr.begin());
        xr = xr ^ (n - 2);
        arr.push_back(n - 2);
    }
    arr.push_back((1LL << 31) - 1);
    xr = xr ^ ((1LL << 31) - 1);
    arr.push_back(xr);

    for (int i = 0 ; i < n; i++) {
        cout << arr[i] << "\t";
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

    int t; 
    scanf("%d", &t);
    while (t--) {
        solve();
    }   

    return 0;
}
