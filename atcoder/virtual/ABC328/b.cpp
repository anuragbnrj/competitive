#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

int numOfDays(int month, int days) {
    int res = 0;
    if (month < 10) {
        if (days >= month) {
            res += 1;
        }

        if (days >= (month * 10 + month)) {
            res += 1;
        }

    } else if (month >= 10 && month < 100) {
        int fd = month / 10;
        int ld = month % 10;

        if (fd == ld) {
            if (days >= ld) {
                res += 1;
            }

            if (days >= month) {
                res += 1;
            }
        }
    } else {

    }

    return res;
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
    cin >> n ;

    int days;

    int res = 0;

    for (int i = 1; i <= n; i++) {
        cin >> days;

        res += numOfDays(i, days);

    }

    cout << res << endl;


    return 0;
}
