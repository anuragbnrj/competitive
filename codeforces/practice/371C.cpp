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
// #define pb push_back
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


bool f(ll m, ll b, ll s, ll c, ll tb, ll ts, ll tc, ll pb, ll ps, ll pc, ll r) {
    ll rb = (m * b) - tb;
    ll rs = (m * s) - ts;
    ll rc = (m * c) - tc;

    if (rb > 0) r -= (rb * pb);
    if (rs > 0) r -= (rs * ps);
    if (rc > 0) r -= (rc * pc);

    if (r < 0) {
        return false;
    } else {
        return true;
    }

}

void solve(string str) {
    // write code here
    ll tb, ts, tc;
    cin >> tb >> ts >> tc;

    ll pb, ps, pc;
    cin >> pb >> ps >> pc;

    ll r;
    cin >> r;

    ll b = 0, s = 0, c = 0;
    fo(i, 0, str.length()) {
        if (str[i] == 'B') {
            b++;
        } else if (str[i] == 'S') {
            s++; 
        } else {
            c++;
        }
    }

    ll ratb = b == 0 ? LONG_LONG_MAX : tb / b;
    ll rats = s == 0 ? LONG_LONG_MAX : ts / s;
    ll ratc = c == 0 ? LONG_LONG_MAX : tc / c;

    ll poss = min(ratb, min(rats, ratc));

    tb -= (poss * b);
    ts -= (poss * s);
    tc -= (poss * c);

    ll mxtb = tb + (r / pb);
    ll mxts = ts + (r / ps);
    ll mxtc = tc + (r / pc);


    ratb = b == 0 ? LONG_LONG_MAX : mxtb / b;
    rats = s == 0 ? LONG_LONG_MAX : mxts / s;
    ratc = c == 0 ? LONG_LONG_MAX : mxtc / c;
    
    ll ri = min(ratb, min(rats, ratc)) + 1;
    ll le = -1;

    while (ri - le > 1) {
        ll m = le + (ri - le) / 2;

        if(f(m, b, s, c, tb, ts, tc, pb, ps, pc, r)) {
            le = m;
        } else {
            ri = m;
        }
    }

    poss = le == -1 ? poss : poss + le;
    
    cout << poss << endl;

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
    string str;
    cin >> str;

    solve(str);

    return 0;
}
