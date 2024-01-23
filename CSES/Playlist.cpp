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

    int n; 
    cin >> n;
    vector<int> songs(n, 0);   

    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    // Method 2:
    // to store largest index from which current element is not present
    // have to use map instead of unordered_map to get AC
    map<int, int> idx;
    int res = INT_MIN;

    for (int curr = 0, beg = 0; curr < n; curr++) {
        beg = max(idx[songs[curr]], beg);

        res = max(res, curr - beg + 1);

        idx[songs[curr]] = curr + 1;
    }

    cout << res << endl;


    // Method 1:
    // int beg = 0, end;
    // int res = INT_MIN;
    // set<int> unique;
    // for (int i = 0; i < n; i++) {
    //     int curr = songs[i];
 
    //     if (unique.count(curr) == 0) {
    //         unique.insert(curr);
    //     } else {
    //         for (int j = beg; j <= end; j++) {
    //             beg = j + 1;
    //             if (songs[j] == curr) {
    //                 break;
    //             } else {
    //                 unique.erase(songs[j]);
    //             }
    //         }
 
    //     }
 
    //     end = i;
 
    //     res = max(res, end - beg + 1);
    // }



    return 0;
}
