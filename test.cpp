#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

template <class T>
using oset = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        sort(hand.begin(), hand.end());
        reverse(hand.begin(), hand.end());

        multiset<pair<int, int>> top;
        for (int i = 0; i < n; i++) {
            int el = hand[i];

            auto it = top.upper_bound({el, -1});
            if (it == top.end() || it->first != (el + 1)) {
                if (groupSize > 1) {
                    top.insert({el, groupSize});
                }  
            } else {
                if (it->second >= 3) {
                    int order = it->second;
                    top.erase(it);
                    top.insert({el, order - 1});
                } else {
                    top.erase(it);
                }
            }
        }

        // for (auto el : top) {
        //     cout << "{" << el.first << ", " << el.second << "} ";
        // }
        // cout << endl;

        if (top.size() > 0) {
            cout << top.size() << endl;
            return false;
        }
 
        return true;
    }
};

int main(void) {
    Solution obj;

    vector<int> arr = {1,1,2,2,3,3};
    int groupSize = 3;

    bool res  = obj.isNStraightHand(arr, groupSize);

    cout << res << endl;

    return 0;
}
