/*
Given

An infinite string: S= "011011100101110111100010011010..."

this is the binary rep of numbers 0,1,2,3,4.... concatenated in a string

q queries:

of the form ?k => you have to find the index of the k-th 1 in this string
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

string get_bit_string(int x) {
    string cur = "";
    while (x) {
        if (x % 2)
            cur += '1';
        else
            cur += '0';
        x /= 2;
    }

    reverse(cur.begin(), cur.end());
    return cur;
}

// cyclic property of bits
// to find sum of 1's upto a number x
int sum_of_bits(int x) {
    int ans = 0;
    int tot = x + 1;

    for (int i = 0; i < 60; i++) {
        int full = (tot / (1LL << (i + 1)));
        int left = (tot % (1LL << (i + 1)));
        int extra = max((left - (1LL << i)), 0LL);
        ans += (full * (1LL << i)) + extra;
    }
    return ans;
}

// BS to find the number containing k-th one
int find_kth_one(int k) {
    int lo = 0, hi = k;
    int ans = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (sum_of_bits(mid) >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// BS se jo number mila usmein humara 1 kis pos pe hai
int find_kth_one_pos_in_num(int x, int k) {
    int cnt = 0;
    string num = get_bit_string(x);
    int i;
    for (i = 0; i < num.size(); i++) {
        if (num[i] == '1')
            cnt++;

        if (cnt == k)
            break;
    }
    return i;
}

int total_bits_till(int x) {
    int ans = 0;
    int len = 1;
    int num = 1;

    while (num <= x) {
        int sametill = (num)-1;
        if (sametill <= x) {
            ans += (sametill - num + 1); // both inclusive
            num = sametill + 1;
            len++;
        } else {
            ans += len * (x - num + 1); // both inclusive
            break;
        }
    }

    return ans + 1;
}

signed main() {
    int q;
    cin >> q;

    while (q--) {
        int k;
        cin >> k;
        int num = find_kth_one(k);

        int pos_in_num = k - sum_of_bits(num - 1);
        int index = find_kth_one_pos_in_num(num, pos_in_num);
        cout << total_bits_till(num - 1) + index << endl;
    }

    return 0;
}