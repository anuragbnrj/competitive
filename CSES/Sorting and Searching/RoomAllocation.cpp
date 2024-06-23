// Problem Link: https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin >> n;
 
    vector<tuple<int, int, int>> ariDep(n);
    for (int i = 0; i < n; i++) {
        int ari, dep;
        cin >> ari >> dep;

        ariDep[i] = {ari, dep, i};
    }
    sort(ariDep.begin(), ariDep.end());
 
    
    priority_queue<int, vector<int>, greater<int>> empty;
    for (int i = 0; i < n; i++) {
        empty.push(i + 1);
    }

    vector<int> result(n, 0);
    int minRoomsReqd = INT_MIN;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;
    for (int i = 0; i < n; i++) {
        while (occupied.size() > 0 && occupied.top().first < get<0>(ariDep[i])) {
            pair<int, int> top = occupied.top();
            occupied.pop();
            empty.push(top.second);
        }

        int room = empty.top();
        empty.pop();

        occupied.push({get<1>(ariDep[i]), room});
        result[get<2>(ariDep[i])] = room;
        minRoomsReqd = max(minRoomsReqd, room);
    }

    cout << minRoomsReqd << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

}  

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
