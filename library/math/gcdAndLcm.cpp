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

// GCD / HCF
int gcdRec (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int gcdRec2 (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int gcdInt (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int gcdFast (int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

long long gcd (long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// LCM
int lcm (int a, int b) {
    return (a / gcd(a, b)) * b;
}

long long lcm (long long a, long long b) {
    return (a / gcd(a, b)) * b;
}
