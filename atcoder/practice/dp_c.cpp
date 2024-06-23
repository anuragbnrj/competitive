// Problem Link:

#include <bits/stdc++.h>

// #include "D:\workspace_cpp\competitive\library\debugging.h"

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// template <class T>
// using oset = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* 
//---- Debugger stdout ---- //
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}
//----------------- //
 */


using namespace std;

#define endl '\n'
using ll = long long;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
ll INFL = 1e18;
int INF = 1e9;

int n;
int a[100005], b[100005], c[100005];
int dp[100005][3];

int rec(int idx, int prevDay) {
    if (idx == n) {
        return 0;
    }

    if (dp[idx][prevDay] != -1) {
        return dp[idx][prevDay];
    }

    int ans = 0;
    if (prevDay == 0) {
        ans = max(ans, rec(idx + 1, 1) + b[idx]);
        ans = max(ans, rec(idx + 1, 2) + c[idx]);
    } else if (prevDay == 1) {
        ans = max(ans, rec(idx + 1, 0) + a[idx]);
        ans = max(ans, rec(idx + 1, 2) + c[idx]);
    } else {
        ans = max(ans, rec(idx + 1, 0) + a[idx]);
        ans = max(ans, rec(idx + 1, 1) + b[idx]);
    }

    return dp[idx][prevDay] = ans;
}


void solve() {
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int ans = 0;
    ans = max(ans, rec(0, 0));
    ans = max(ans, rec(0, 1));
    ans = max(ans, rec(0, 2));

    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
