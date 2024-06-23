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

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    vector<int> res;
    int ctr = 0;
    bool flag = false;
    for (int i = 0; ctr < n; i = (i + 1) % n) {

        if (arr[i] != 1e9) {
            if (flag == false) {

            } else {
                res.push_back(arr[i]);
                arr[i] = 1e9;
                ctr++;
            }

            flag = !flag;
        }

    }


    for (int i = 0; i < (int) res.size(); i++) {
        cout << res[i] << " ";
    }  

    cout << endl;

    return 0;
}
