#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007


bool customComparator(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
    if (a.first.first == b.first.first) {
        return a.first.second > b.first.second;
    } 
    return a.first.first < b.first.first;
}

void printVector(vector<int> &arr) {
    int len = arr.size();

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
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

    int n; 
    cin >> n;

    vector< pair< pair<int, int>, int> > intervals;
    for (int i = 0; i < n; i++) {
        int beg, end;
        cin >> beg >> end;
        intervals.push_back({{beg, end}, i});
    }
    sort(intervals.begin(), intervals.end(), customComparator);

    vector<int> contains(n, 0);
    int minEnd = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        int curEnd = intervals[i].first.second;
        int pos = intervals[i].second;

        if (minEnd <= curEnd) {
            contains[pos] = 1;
        }

        minEnd = min(minEnd, curEnd);
    }

    vector<int> isContained(n, 0);
    int maxEnd = INT_MIN;
    for (int i = 0; i < n; i++) {
        int curEnd = intervals[i].first.second;
        int pos = intervals[i].second;

        if (curEnd <= maxEnd) {
            isContained[pos] = 1;
        }

        maxEnd = max(maxEnd, curEnd);
    }

    printVector(contains);
    printVector(isContained);

    return 0;
}
