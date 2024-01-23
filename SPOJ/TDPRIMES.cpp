#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define mod 1000000007
#define fo(i, st, end) for (int i = st; i < end; i++)
#define foeq(i, st, end) for (int i = st; i <= end; i++)
#define revfo(i, st, end) for (int i = st; i > end; i--)
#define revfoeq(i, st, end) for (int i = st; i >= end; i--)
#define foit(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define clr(x) memset(x, false, sizeof(x))
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define deb(x) cout << #x << "=" << x << endl


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;
typedef vector< int > vi;
typedef vector< ll > vll;
typedef vector< pii > vpii;
typedef vector< pllll > vpllll;
typedef vector< vi > vvi;
typedef vector< vll > vvll;



vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    int ctr = 0;
    for (int i = 2; i < n + 1; i++) {
        if (is_prime[i]) {
            ctr++;
        }

        if (ctr % 100 == 1 && is_prime[i]) {
            cout << i << endl;
        }
    }
    return is_prime;
}


void solve() {
    sieve(100000000);
} 

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    // int n;
    // cin >> n;

    solve();

    
    return 0;
}
