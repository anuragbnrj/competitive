// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int max_len = 0;

        unordered_map<char, int> mpp;

        for(int beg = 0, end = 0; end < len; end++) {
            char ch = s[end];
            if (mpp.count(ch)) {
                mpp[ch] += 1;
            } else {
                mpp[ch] = 1;
            }

           while (mpp.count(ch) && mpp[ch] > 1) {
               char rm_ch = s[beg];
               mpp[rm_ch] -= 1;
               beg++;
           }

           int cur_len = end - beg + 1;

           max_len = max(max_len, cur_len);
        }

        return max_len;
    }
};