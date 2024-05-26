// Problem Link: https://atcoder.jp/contests/abc215/tasks/abc215_d

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

int len = 1000003;
// spf will store the smallest prime factor of i
// if spf[i] == i, then i is a prime number
vector<int> spf(len + 1); 
void generateSmallestPrimeFactors() {
    // fills the vector with values starting from 0. Eg: 0, 1, 2, 3, ...
    iota(spf.begin(), spf.end(), 0);

    for (int i = 2; i*i <= len; i++) { // O(N log log N)
        if (spf[i] == i) {
            for (int j = i*i ; j <= len; j = j + i) {
                if (spf[j] == j) {
                    spf[j] = i; 
                }
            }
        }
    }

    // This is to prevent treating 0 and 1 as prime numbers;
    spf[0] = 1;
    spf[1] = 2;

}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    vector<int> freq(len, 0);
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        if (temp == 1) {
            continue;
        }

        while (spf[temp] != temp) {
            freq[spf[temp]]++;
            temp /= spf[temp];
        }

        if (spf[temp] > 1) {
            freq[spf[temp]]++;
        }
    }

    vector<int> res;
    res.push_back(1);
    for (int i = 2; i <= m; i++) {
        int temp = i;
        bool flag = true;
        while (spf[temp] != temp) {
            if (freq[spf[temp]] > 0) {
                flag = false;
                break;
            }

            temp /= spf[temp];
        }

        if (flag && spf[temp] > 1 && freq[spf[temp]] > 0) {
           flag = false;
        }

        if (flag) {
            res.push_back(i);
        }
    }

    int resLen = res.size();
    cout << resLen << endl;
    for (int i = 0; i < resLen; i++) {
        cout << res[i] << endl;
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

    generateSmallestPrimeFactors();

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
