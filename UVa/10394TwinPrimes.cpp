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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pllll> vpllll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    return is_prime;
}


void solve() {
    // write code here
    vector<bool> isPrime = sieve(20000000);

    unordered_map<int, int> primePairs;

    int count = 1;
    fo(i, 5, isPrime.size()) {
        if (isPrime[i] && isPrime[i - 2]) {
            primePairs.insert({count++, i});
        }
    }

    int s;
    while (cin >> s) {
        auto it = primePairs.find(s);
        cout << "(" << (it->S - 2) << ", " << it->S << ")" << endl;
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

    // for handling problems in which test cases are not required
    // int n;
    // cin >> n;

    
    //write code here
    solve();

    return 0;
}
