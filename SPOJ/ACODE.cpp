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

string str;
vector<ll> dp;

ll rec(int idx) {
    if (idx == str.size()) {
        return 1;
    }

    if (dp[idx] != -1LL) {
        return dp[idx];
    }

    ll ans = 0;
    char ch = str[idx];
    if (ch == '0') {
        ans = 0;
    } else if (ch == '1') {
        if (idx == str.size() - 1) {
            ans = rec(idx + 1);
        } else {
            char next = str[idx + 1];
            if (next == '0') {
                ans = rec(idx + 2);
            } else {
                ans = rec(idx + 1) + rec(idx + 2);
            }
        }
    } else if (ch == '2') {
        if (idx == str.size() - 1) {
            ans = rec(idx + 1);
        } else {
            char next = str[idx + 1];
            if (next == '0') {
                ans = rec(idx + 2);
            } else if (next == '7' || next == '8' || next == '9') {
                ans = rec(idx + 1);
            } else {
                ans = rec(idx + 1) + rec(idx + 2);
            }
        }
    } else {
        ans = rec(idx + 1);
    }

    return dp[idx] = ans;
}

void solve() {
    dp.assign(str.size() + 1, -1LL);
    int ans = rec(0);
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

    cin >> str;
    while (str != "0") {
        solve();
        cin >> str;
    }

    return 0;
}
