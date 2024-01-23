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

    int x, n; 
    cin >> x >> n;

    multiset<int> lengths;
    set<int> points;

    points.insert(0);
    points.insert(x);
    lengths.insert(x);

    for (int i = 0; i < n; i++) {
        int point;
        cin >> point;
        points.insert(point);

        auto it = points.lower_bound(point);

        it--;
        int prev = *it;

        it++;
        it++;
        int next = *it;


        int dist = next - prev;
        auto it2 = lengths.lower_bound(dist);
        lengths.erase(it2);

        lengths.insert(point - prev);
        lengths.insert(next - point);

        auto it3 = lengths.rbegin();

        cout << *it3 << " ";
    }

    cout << endl;

    return 0;
}
