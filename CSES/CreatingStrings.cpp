#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve(int idx, string str, set<string> &res) {
    if (idx == ((int)str.size() - 1)) {
        res.insert(str);
        return;
    }


    for (int i = idx; i < (int)str.size(); i++) {
        char ch1 = str[idx];
        char ch2 = str[i];
        str[idx] = ch2;
        str[i] = ch1;
        solve(idx + 1, str, res);
    }
}


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

    sort(str.begin(), str.end());

    set<string> res;

    solve(0, str, res);

    // do {
    //     res.insert(str);
    // } while (next_permutation(str.begin(), str.end()));

    cout << res.size() << endl;
    for (auto el : res) {
        cout << el << endl;
    }

    return 0;
}
