// Problem Link: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;



vector<long long> printFirstNegativeInteger(long long int arr[], long long int len, long long int k) {
    set<long long> negativeIndices;
    vector<long long> res;
    for (int beg = 0, end = 0; end < len; end++) {
        if (arr[end] < 0) {
            negativeIndices.insert(end);
        }
        
        int currLen = end - beg + 1;
        while (currLen > k) {
            if (arr[beg] < 0) {
                negativeIndices.erase(beg);
            }
            beg++;
            currLen = end - beg + 1;
        }
        
        if (currLen == k) {
            if (negativeIndices.size() > 0) {
                auto it = negativeIndices.begin();
                int idx = *it;
                int element = arr[idx];
                res.push_back(element);
            } else {
                res.push_back(0);
            }
        }
        
    }
    
    return res;
 }