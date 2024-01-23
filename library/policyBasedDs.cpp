#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

// typedef tree<
//     pair<long long, int>,
//     null_type,
//     less<pair<long long, int>>,
//     rb_tree_tag,
//     tree_order_statistics_node_update>
//     pbds_set;

template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


class Solution {
public:
    int reversePairs(vector<int> &nums) {
        int len = nums.size();

        oset<long long> stt;
        int res = 0;
        for (int i = len - 1; i >= 0; i--) {
            int temp = stt.order_of_key(nums[i] * 1LL);
            res = res + temp;
            stt.insert(nums[i] * 2LL);
        }

        return res;
    }
};

int main() {
    Solution obj;
    vector<int> vec = {2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647};

    int res = obj.reversePairs(vec);
    cout << "res: " << res << endl;
 
    return 0;
}

// int main() {
// 	pbds_set St;
// 	St.insert(1);

// 	for (int i = 0; i < St.size(); i++) {
// 		cout << i << " -> " << *St.find_by_order(i) << '\n';
// 	}

//     cout << endl;
// 	for (int i = 0; i < 15; i++) {
// 		cout << i << " -> " << St.order_of_key(i) << '\n';
// 	}

//     return 0;

// }
