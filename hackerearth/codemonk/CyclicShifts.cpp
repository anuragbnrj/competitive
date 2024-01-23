#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

void solve() {
    int n, k;
    cin >> n >> k;
    
    string a;
    cin >> a;

    string mx = a;
    string temp = a;
    long long initIter = 0;

    for (int i = 1; i <= n; i++) {
        temp = temp.substr(1) + temp.substr(0, 1);

        if (temp > mx) {
            mx = temp;
            initIter = i;
        }
    }

    long long shifts = 0;
    temp = mx;
    do {
        temp = temp.substr(1) + temp.substr(0, 1);
        shifts++;
    }  while (temp != mx);

    // while (temp != mx) {
    //     temp = mx.substr(1) + mx.substr(0, 1);
    //     shifts++;
    // }


    long long res = 0;
    k = k - 1;

    res = k * shifts * 1LL + initIter;

    // cout << "mx: " << mx << "\t initIter: " << initIter << "\t shifts: " << shifts << "\t";
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

    int t;
    cin >> t;

    
	while (t--) {
		solve();
	}  

    return 0;
}
