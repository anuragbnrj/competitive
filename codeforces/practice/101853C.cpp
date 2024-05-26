// Problem Link: https://codeforces.com/gym/101853/problem/C

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> pos;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }

    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        int num = a[i];
        int idx = pos[num];

        temp[idx] = i;
    }

    oset<int> stt;
    ll count = 0;
    for (int i = 0; i < n; i++) {
        int sz = stt.size();
        int order = stt.order_of_key(temp[i]);
        count = count + (sz - order); 
        stt.insert(temp[i]);
    }

    cout << count << endl;

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
