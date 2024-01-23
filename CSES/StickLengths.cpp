#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007


long long calcDiff(long long len, vector<int> &arr) {
    long long sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += abs(len - arr[i]);
    }

    return sum;
}


int isValley(int len, vector<int> &arr) {
    long long prev = calcDiff(len - 1, arr);
    long long curr = calcDiff(len, arr);
    long long next = calcDiff(len + 1, arr);


    if (prev >= curr && curr <= next) {
        return 0;
    } else if (prev > curr && curr > next) {
        return 1;
    } else {
        return -1;
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

    int n;
    cin >> n;
    
    vector<int> arr(n);
    int mn = INT_MAX;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }


    int beg = mn;
    int end = mx;

    int len = 0;

    while (beg <= end) {
        int mid = beg + ((end - beg) / 2);

        if (isValley(mid, arr) == 0) {
            len = mid;
            break;
        } else if (isValley(mid, arr) == 1) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << calcDiff(len,  arr) << endl;

    return 0;
}
