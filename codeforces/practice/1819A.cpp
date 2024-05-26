// Problem Link: https://codeforces.com/contest/1819/problem/A

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

int getMex(vector<int> &a) {
    int n = a.size();
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    int mex = 0;
    for (int i = 0; i < n; i++) {
        if (temp[i] == mex) {
            mex = mex + 1;
        }
    }

    return mex;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mex = getMex(a);
    int mexPlusOne = mex + 1;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == mexPlusOne) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == mexPlusOne) {
            r = i;
            break;
        }
    }

    
    if (l != -1) {
        for (int i = l; i <= r; i++) {
            a[i] = mex;
        }

        int newMex = getMex(a);
        if (newMex == mexPlusOne) {
            cout << "Yes" << endl;
            return;
        } else {
            cout << "No" << endl;
            return;
        }
        
    } else {
        if (n >= mex + 1) {
            cout << "Yes" << endl;
            return;
        } else {
            cout << "No" << endl;
            return;
        }
    }

    cout << mex << endl;

}  

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    // solve(); 
    
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
