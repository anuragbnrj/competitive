#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int len = str.size();

    int currCount = 1;
    int maxCount = 1;
    for (int i = 1; i < len; i++) {
        if (str[i] == str[i - 1]) {
            currCount++;
            maxCount = max(maxCount, currCount);
        } else {
            currCount = 1;
        }
    }

    cout << maxCount << endl;    

    return 0;
}
