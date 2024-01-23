#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007


void solve() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    vector<int> res;
    set<int> used;
    int mxor = 0;
    int end = log(a[0]) / log(2);
    for (int i = 0; i <= end; i++) {
        int mx = 0;
        int mxidx = -1;
        int temp = mxor;
        for (int j = 0; j < n; j++) {
            if (!used.count(j)) {
                if ((mxor | a[j]) > temp) {
                    temp = mxor | a[j];
                    mx = a[j];
                    mxidx = j;
                }
            }
        }
        
        if (mxidx != -1) {
            res.push_back(mx);
            used.insert(mxidx);
            mxor = mxor | mx;
        }
        
    }

    for (int i = 0; i < n; i++) {
        if (!used.count(i)) {
            res.push_back(a[i]);
        }
    }

    // vector<vector<int>> msbarr(41);
    // for (int i = 0; i < n; i++) {
    //     int msb = 0;
    //     int temp = a[i];
    //     while (temp > 0) {
    //         msb++;
    //         temp = temp >> 1;
    //     }

    //     msbarr[msb].push_back(a[i]);
    // }

    // vector<int> res;
    // for (int i = 40; i >= 0; i--) {
    //     if (msbarr[i].size() > 0) {
    //         res.push_back(msbarr[i].back());
    //         msbarr[i].pop_back();
    //     }
    // }

    // for (int i = 40; i >= 0; i--) {
    //     int len = msbarr[i].size();
    //     while (msbarr[i].size() > 0) {
    //         res.push_back(msbarr[i].back());
    //         msbarr[i].pop_back();
    //     }
    // }

    for (int i = 0; i < n; i++) {
        cout << res[i] << "\t";
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
    cin >> t; 
    while (t--) {
        solve();
    }   

    return 0;
}
