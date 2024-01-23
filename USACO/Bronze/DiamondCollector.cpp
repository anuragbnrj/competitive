#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve(int n, int k, vector<int> sizes) {
    int mxDiams = 0;

    for (int i = 0; i < n; i++) {
        int currDiams = 0;
        for (int j = 0; j < n; j++) {
            int diff = sizes[j] - sizes[i];
            if (diff >= 0 && diff <= k) {
                currDiams++;
            }
        }

        mxDiams = max(mxDiams, currDiams);
    }

    cout << mxDiams << endl;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; 
    cin >> n >> k;

    vector<int> sizes(n);
    for (int &el : sizes) {
        cin >> el;
    }

    solve(n, k, sizes);  

    return 0;
}
