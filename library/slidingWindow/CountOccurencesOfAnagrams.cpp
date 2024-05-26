// Problem Link: https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

/*
Sample Test Cases:
aabaabaa
aaba

kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkk

forxxorfxdofr
for
*/

class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    vector<int> freqPat(26, 0);
        int distinctRequired = 0; 
	    for (char ch : pat) {
            if (freqPat[ch - 'a'] == 0) {
                distinctRequired++;
            }
	        freqPat[ch - 'a']++;
	    }
	    
	    vector<int> freqWindow(26, 0);
	    int lenTxt = txt.size();
	    int lenPat = pat.size();
	    // int req = pat.size();
	    int count = 0;
	    for (int beg = 0, end = 0; end < lenTxt; end++) {
	        char ch = txt[end];
            freqWindow[ch - 'a']++;
	        if (freqPat[ch - 'a'] > 0 && freqWindow[ch - 'a'] == freqPat[ch - 'a']) {
	            distinctRequired--;
	        }
	        
	        while(end - beg + 1 > lenPat) {
	            char temp = txt[beg];
	            if (freqPat[temp - 'a'] > 0 && freqWindow[temp - 'a'] == freqPat[temp - 'a']) {
	                distinctRequired++;
	            }
                freqWindow[temp - 'a']--;

	            beg++;
	        }
	        
	        if (end - beg + 1 == lenPat && distinctRequired == 0) {
	            count++;
	        }
	    }
	    
	    return count;
	}

};