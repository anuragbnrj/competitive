// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

// Function for finding sum of large numbers that do not fit in long long
string findSum(string str1, string str2) {
    if (str1.length() > str2.length()) {
        swap(str1, str2);
    }

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int n1 = str1.length(), n2 = str2.length();

    int carry = 0;
    string str = "";
    for (int i = 0; i < n1; i++) {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++) {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry) {
        str.push_back(carry + '0');
    }
        
    reverse(str.begin(), str.end());

    return str;
}

int main() {
    string str1 = "111111111111111111111111111111111111";
    string str2 = "999999999999999999999999999999";
    // string str2 = "111111111111111111111111111111111111";
    cout << findSum(str1, str2);

    return 0;
}
