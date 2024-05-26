// Problem Link: https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> deadlineDuration;
    for (int i = 0; i < n; i++) {
        int duration, deadline;
        cin >> duration >> deadline;

        deadlineDuration.push_back({duration, deadline});
    }

    sort(deadlineDuration.begin(), deadlineDuration.end());

    // Check youtube video from NeatlyStructured Channel for proof of why this works
    ll res = 0, currTime = 0;
    for (int i = 0; i < n; i++) {
        currTime += deadlineDuration[i].first;
        res += (deadlineDuration[i].second - currTime);
    }

    cout << res << endl;
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

    return 0;
}
