// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;

struct CustomDS {
    int k;
    multiset<int> bottom, topK;
    ll sumTopK;

    void init(int _k) {
        k = _k;
        sumTopK = 0;
    }

    void insert(int x) {
        topK.insert(x);
        sumTopK += x;

        if (topK.size() > k) {
            auto it = topK.begin();
            int val = *it;
            bottom.insert(val);
            topK.erase(it);
            sumTopK -= val;
        }
    }

    void remove(int x) {
        if (topK.find(x) != topK.end()) {
            topK.erase(topK.find(x));
            sumTopK -= x;
        } else {
            if (bottom.find(x) != bottom.end()) {
                bottom.erase(bottom.find(x));
            }
        }

        if (topK.size() < k && !bottom.empty()) {
            auto it = bottom.end(); it--;
            int val = *it;
            topK.insert(val);
            sumTopK += val;
            bottom.erase(it);
        }
    }

    ll getTopKSum() {
        return sumTopK;
    } 
};

void solve() {
    int q, k;
    cin >> q >> k;

    CustomDS ds;
    ds.init(k);

    

    while (q--) {
        int num, x;
        cin >> num;

        
        if (num == 1) {
            cin >> x;
            ds.insert(x);
        } else if (num == 2) {
            cin >> x;
            ds.remove(x);
        } else {
            char qmark;
            cin >> qmark;

            cout << ds.getTopKSum() << endl;
        }
    }

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
