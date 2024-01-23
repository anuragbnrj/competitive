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

    vector<int> arr(n);
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = 1;
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        int next = curr + 1;

        if (curr < n) {
            if (pos[curr] > pos[next]) {
                rounds += 1;
            }
        }
        
    }

    cout << rounds << endl;
    

    return 0;
}
