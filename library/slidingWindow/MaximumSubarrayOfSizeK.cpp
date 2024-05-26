// Problem Link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;


class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        
        long long currSum = 0;
        long long maxSum = LLONG_MIN;
        for (int beg = 0, end = 0; end < n; end++) {
            currSum += arr[end];
            
            while (beg < end && (end - beg + 1) > k) {
                currSum -= arr[beg];
                beg++;
            }
            
            if (end - beg + 1 == k && currSum > maxSum) {
                maxSum = currSum;
            }
        }
        
        return maxSum;
        
    }
};
