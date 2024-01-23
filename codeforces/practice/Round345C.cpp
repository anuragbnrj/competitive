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

bool sortByX(std::pair<int, int> lhs, std::pair<int, int> rhs) {
    if (lhs.first < rhs.first) {
        return true;
    }
    else if (lhs.first == rhs.first && lhs.second < rhs.second) {
        return true;
    }
    else {
        return false;
    }
}

bool sortByY(std::pair<int, int> lhs, std::pair<int, int> rhs) {
    if (lhs.second < rhs.second) {
        return true;
    }
    else if (lhs.second == rhs.second && lhs.first < rhs.first) {
        return true;
    }
    else {
        return false;
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
    int n;
    cin >> n;

    vpl wm;

    fo (i, n) {
        ll x;
        ll y;

        cin >> x >> y;

        wm.pb({x, y});
    }

    ll res = 0ll;

    sort(wm.begin(), wm.end(), sortByX);
    int count = 1;
    for (int i = 1; i < n; i++) {
        while (wm[i].F == wm[i - 1].F && i < n) {
            res += count;
            count++;
            i++;
        }

        count = 1;
    }

    sort(wm.begin(), wm.end(), sortByY);
    count = 1;
    for (int i = 1; i < n; i++) {
        while (wm[i].S == wm[i - 1].S && i < n) {
            res += count;
            count++;
            i++;
        }

        count = 1;
    }

    count = 1;
    for (int i = 1; i < n; i++) {
        while (wm[i].F == wm[i - 1].F && wm[i].S == wm[i - 1].S && i < n) {
            res -= count;
            count++;
            i++;
        }

        count = 1;
    }

    cout << res;

    return 0;
}
