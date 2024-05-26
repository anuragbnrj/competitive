#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

// algozenith template
// first 1 in the array [0 0 0 0 0 1 1 1 1 1]
/*
int lo = 0;
int hi = N - 1;
int ans = hi + 1;
while (lo < hi) {
    mid = lo + (hi - lo) / 2;
    if (a[mid] == 0) {
        lo = mid + 1;
    } else {
        ans = mid;
        hi = mid - 1;
    }
}

return ans;
*/


// Function for calculating the lower bound
// Return the first index GREATER THAN OR EQUAL to the target
// OR N(size of nums) if no such index exists
int lower_bound_custom(vector<int> nums, int target) {
    int len = nums.size();
    int beg = 0;
    int end = len;
    while (beg < end) {
        int mid = beg + (end - beg) / 2;
        if (nums[mid] < target) beg = mid + 1;
        else end = mid;
    }
    return beg;
}

// Function for calculating the upper bound
// Return the first index GREATER THAN the target
// OR N(size of nums) if no such index exists
int upper_bound_custom(vector<int> nums, int target) {
    int len = nums.size();
    int beg = 0;
    int end = len;
    while (beg < end) {
        int mid = beg + (end - beg) / 2;
        if (nums[mid] <= target) beg = mid + 1;
        else end = mid;
    }
    return beg;
}

/* 
int BSfindFirst(int start, int end, int val) {
	while(start < end) {
		int mid = start + (end-start)/2;
		if(f(mid) < val)		start= mid+1;
		else if(f(mid) > val)	end  = mid-1;
		else					end  = mid;
	}
	return start;
}
 */

/* 
int BSfindLast(int start, int end, int val) {
	while(start < end) {
		int mid = start + (end-start+1)/2;
		if(f(mid) < val)		start= mid+1;
		else if(f(mid) > val)	end  = mid-1;
		else					start= mid;
	}
	return start;
}
 */
int main() {
    int a[] = {4,5,8,9,9,9,9,9,12,13,16,17,20,21};
    int len = sizeof(a) / sizeof(int);
    int search_el = 9;

    auto lb = lower_bound(a, a + len, search_el);
    auto ub = upper_bound(a, a + len, search_el);
    auto er = equal_range(a, a + len, search_el);


    cout << "length: " << len << endl;
    cout << "lower bound idx: " << lb - a << endl;
    cout << "upper bound idx: " << ub - a << endl;
    cout << "upper - lower: " << ub - lb << endl;
    cout << "equal_range: " << er.second - er.first << endl;


    int l = -1, r = len;
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(search_el < a[m]) {
            r = m; // a[l] <= k < a[m] <= a[r]
        } else {
            l = m; // a[l] <= a[m] <= k < a[r]
        }
    }

    cout << "l: " << l << endl;
    cout << "r: " << r << endl;

    return 0;
}
