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
        cin >> arr[i];
    } 

    set<pair<int, int>> towers;   

    // priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int el = arr[i];

        auto iterator = towers.upper_bound({el, i});

        if (iterator == towers.end()) {
            towers.insert({el, i});
        } else {
            int temp = iterator->first;

            if (temp > el) { 
                towers.erase(iterator);
                
            } 

            towers.insert({el, i});
        }

    }


    cout << towers.size() << endl;

    return 0;
}
