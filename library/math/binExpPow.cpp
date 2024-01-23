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


long long binPow(long long x, long long y) {
    long long res = 1;

    while (y > 0) {
        if (y & 1) {
            res = res * x;
        }

        x = x * x;
        y >>= 1;
    }

    return res;
}


long long binPowMod(long long x, long long y, long long z) {
    long long res = 1;
    x = x % z;

    while (y > 0) {
        if (y & 1) {
            res = res * x % z;
        }

        x = x * x % z;
        y >>= 1;
    }

    return (res % z);
}
