#include <bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

ll bigMod(ll x, ll y, ll z) {
    // write code here

    ll res = 1;
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

string leading(ll n, ll k) {
    // write code here

    double y = k * log(n) / log(10);
    string s = to_string(y);

    int pos = s.find(".");
    string pwr = s.substr(pos + 1);
    pwr = "0." + pwr;

    double res = pow(10, stod(pwr));
    res = res * 1000;

    string temp = to_string(res);
    temp = temp.substr(0, 3);

    return temp;
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

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        string le = leading(n, k);
        string tr =  to_string(bigMod(n, k, 1000));

        if (tr.length() == 1) {
            tr = "00" + tr;
        } else if (tr.length() == 2) {
            tr = "0" + tr;
        }

        cout << le << "..." << tr << endl; 
    }

    return 0;
}
