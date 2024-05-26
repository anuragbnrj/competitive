#include <bits/stdc++.h>
using namespace std;

// find xor of interval [0, n]
int findXORUptoN(int n) {
    int rem = n % 4;

    int res = 0;
    switch (rem) {
    case 0:
        res = n;
        break;
    case 1:
        res = 1;
        break;
    case 2:
        res = n + 1;
        break;
    case 3:
        res = 0;
        break;
    }

    return res;
}

// find the submasks of masks
void submask() {
    vector<int> arr = {2, 3, 5};
    int n = arr.size();

    for (int mask = 0; mask < (1 << n); mask++) { // 2*n
        cout << mask << endl;
        for (int submask = mask;; submask = (submask - 1) & mask) {
            for (int i = 0; i < n; i++) {
                if ((submask >> i) & 1) {
                    cout << arr[i] << ", ";
                }
            }
            cout << endl;

            if (submask == 0)
                break;
        }
        cout << endl;
    }
}

// reverse a number represented in binary
void reverse() {
    unsigned int x;
    cin >> x;
    x |= (1 << 30);
    cout << bitset<32>(x) << endl;
    // reverse

    x = ((x & 0xFFFF0000) >> 16) | ((x & 0x0000FFFF) << 16);
    x = ((x & 0xFF00FF00) >> 8) | ((x & 0x00FF00FF) << 8);
    x = ((x & 0xF0F0F0F0) >> 4) | ((x & 0x0F0F0F0F) << 4);
    x = ((x & 0xCCCCCCCC) >> 2) | ((x & 0x33333333) << 2);
    x = ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);

    // after reverse
    cout << bitset<32>(x) << endl;
}

// Number of set bits at ith position in the interval [0, x]
long long setBitsAtIdx(int i, long long x) {
    long long totalNumbersPresent = (x + 1);
    long long boxsize = (1LL << (i + 1));

    long long fullboxes = totalNumbersPresent / boxsize;
    long long ans = fullboxes * (1LL << i);

    long long extra = totalNumbersPresent % boxsize;
    ans += max(extra - (1LL << i), 0LL);
    return ans;
}

int main() {
    int l, r;
    cin >> l >> r;

    int ans = 0;
    for (int i = 0; i < 30; i++) {
        int cnt1 = setBitsAtIdx(i, r) - setBitsAtIdx(i, l - 1);
        if (cnt1 == (r - l + 1)) {
            ans |= (1 << i);
        }
    }
    cout << ans << endl;
}
