#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define mod 1000000007
#define fo(i, st, end) for (int i = st; i < end; i++)
#define foeq(i, st, end) for (int i = st; i <= end; i++)
#define revfo(i, st, end) for (int i = st; i > end; i--)
#define revfoeq(i, st, end) for (int i = st; i >= end; i--)
#define foit(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define clr(x) memset(x, false, sizeof(x))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define deb(x) cout << #x << "=" << x << endl


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pllll> vpllll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// Function for calculating the lower bound
// Return the first index GREATER THAN OR EQUAL to the target
// OR N(size of nums) if no such index exists
// int lower_bound_custom(vector<int> nums, int target){
//     int len = nums.size();
//     int start = 0;
//     int end = len;
//     while (start < end) {
//         int mid = start + (end - start) / 2;
//         if (nums[mid] < target) start = mid + 1;
//         else end = mid;
//     }
//     return start;
// }

// Function for calculating the upper bound
// Return the first index GREATER THAN the target
// OR N(size of nums) if no such index exists
// int upper_bound_custom(vector<int> nums, int target){
//     int len = nums.size();
//     int start = 0;
//     int end = len;
//     while (start < end) {
//         int mid = start + (end - start) / 2;
//         if (nums[mid] <= target) start = mid + 1;
//         else end = mid;
//     }
//     return start;
// }


// int BSfindFirst(int start, int end, int val) {
// 	while(start < end) {
// 		int mid = start + (end-start)/2;
// 		if(f(mid) < val)		start= mid+1;
// 		else if(f(mid) > val)	end  = mid-1;
// 		else					end  = mid;
// 	}
// 	return start;
// }

// int BSfindLast(int start, int end, int val) {
// 	while(start < end) {
// 		int mid = start + (end-start+1)/2;
// 		if(f(mid) < val)		start= mid+1;
// 		else if(f(mid) > val)	end  = mid-1;
// 		else					start= mid;
// 	}
// 	return start;
// }

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

    // for handling problems in which test cases are not required
    // int n;
    // cin >> n;

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
    cout << "equal_range: " << er.S - er.F << endl;


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
