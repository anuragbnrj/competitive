// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;

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

int freq[2000020];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < 2000020; i++) {
        freq[i] = 0;
    }

    vector<int> a(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        total += a[i];
    }

    for (int i = 1; i < 2000020; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }

    // sort(a.begin(), a.end());
    // pr(a);
    // int temp = 0;
    // for (int i = 0; i < a.size(); i++) {
    //     int contri = 0;
    //     for (int j = i + 1; j < a.size(); j++) {
    //         contri += max(a[i], a[j]) / min(a[i], a[j]);
    //     }

    //     temp += contri;
    //     cout << "i: " << a[i] << ", contri: " << contri << ", res: " << temp << endl;
       
    // }
    // cout << temp << endl;

    ll res = 0;
    if (freq[1] > 0) {
        res += (total - freq[1]) * freq[1] + (freq[1] - 1);
    }
    for (int i = 2; i <= 1000010; i++) {
        int selfCount = (freq[i] - freq[i - 1]);    
        if (selfCount > 0) {
            ll contri = 0;
            for (int j = i + i; j <= 2000020; j += i) {
                ll countInInterval = freq[j - 1] - freq[j - 1 - i];

                contri += countInInterval * ((j - 1) / i);
            }
            
            contri -= selfCount;

            res += (contri * selfCount);
            res += selfCount - 1;

            // cout << "i: " << i << ", contri: " << contri << ", selfCount: " << selfCount << ", res: " << res << endl;
        }
    }

    cout << res << endl;
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
