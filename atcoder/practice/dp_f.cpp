// Problem Link:

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// #include "D:\workspace_cpp\competitive\library\debugging.h"

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// template <class T>
// using oset = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
ll INFL = 1e18;
int INF = 1e9;


string s, t;
int n, m;
int dp[3010][3010];
int mv[3010][3010];

int rec(int i, int j) {
    // cout << "i: " << i << ", j: " << j << ", n: " << n << ", m: " << m << endl;
    if (i == n && j == m) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = 0;
    if (i < n) {
        if (rec(i + 1, j) >= ans) {
            ans = rec(i + 1, j);
            mv[i][j] = 0;
        }
    }

    if (j < m) {
        if (rec(i, j + 1) >= ans) {
            ans = rec(i, j + 1);
            mv[i][j] = 1;
        }
    }
    
    if (i < n && j < m) {
        if (s[i] == t[j]) {
            if (rec(i + 1, j + 1) + 1 >= ans) {
                
                ans = rec(i + 1, j + 1) + 1;
                mv[i][j] = 2;
            }
        }
    }

    return dp[i][j] = ans;
}

void generate(int i, int j) {
    if (i == n && j == m) {
        return;
    }

    if (mv[i][j] == 0) {
        generate(i + 1, j);
    } else if (mv[i][j] == 1) {
        generate(i, j + 1);
    } else if (mv[i][j] == 2) {
        cout << s[i];
        generate(i + 1, j + 1);
    }
}

void solve() {
    cin >> s >> t;
    n = s.size();
    m = t.size();

    memset(dp, -1, sizeof(dp));
    int ans = rec(0, 0);
    // cout << ans << endl;
    generate(0, 0);
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
