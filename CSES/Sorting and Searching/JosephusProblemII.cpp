#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007


template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; 
    cin >> n >> k;

    oset<int> stt;
    for (int i = 1; i <= n; i++) {
        stt.insert(i);
    }

    int curr = 0;
    int ctr = 0;

    while (ctr < n) {
        curr = (curr + k) % stt.size();

        auto it = stt.find_by_order(curr);

        cout << *it << " ";
        stt.erase(it);
        ctr++; 
    }
    

    return 0;
}
