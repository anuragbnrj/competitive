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


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    int a, b;
    cin >> a >> b;

    int res = INT_MAX;

    if (a == b) {
        cout << 0;
        return 0;
    } else {
        int a2 = 0, a3 = 0, a5 = 0, b2 = 0, b3 = 0, b5 = 0;

        while (a % 2 == 0) {a /= 2; a2++;}
        while (a % 3 == 0) {a /= 3; a3++;}
        while (a % 5 == 0) {a /= 5; a5++;}

        while (b % 2 == 0) {b /= 2; b2++;}
        while (b % 3 == 0) {b /= 3; b3++;}
        while (b % 5 == 0) {b /= 5; b5++;}

        if (a != b) {cout << "-1"; return 0;}

        int res = abs(a2 - b2) + abs(a3 - b3) + abs(a5 - b5);
        cout << res;
    }

    return 0;
}
