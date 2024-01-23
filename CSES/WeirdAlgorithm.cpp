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


    long long n; 

    cin >> n;

    while (true) {
        cout << n << endl;
        
        if (n == 1) {
            return 0;
        }


        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
    }

    return 0;
}
