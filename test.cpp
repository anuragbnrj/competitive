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
    int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int, int> freq2;
        for (int i = 0; i < n2; i++) {
            freq2[nums2[i]]++;
        }

        int res = 0;
        for (int x = -5; x <= 5; x++) {
            unordered_map<int, int> freq1;

            for (int i = 0; i < n1; i++) {
                freq1[nums1[i] + x]++;
            }

            int diff = 0;
            for (auto el : freq1) {
                int num = el.first;
                int freq = el.second;

                diff += abs(num - freq2[num]);
            }

            if (diff == 2) {
                res = x;
                break;
            }
        }

        return res;
    }
};

int main(void) {
    Solution obj;

    int n = 10;

    for (int i = 0; i <= n; i++) {
        int xr = (n ^ i);
        int sum = (n + i);
        if (xr == sum) {
            cout << "n: " << n << ", i: " << i << ", XOR: " << xr << ", SUM: " << sum << endl;
        }
    }

    return 0;
}
