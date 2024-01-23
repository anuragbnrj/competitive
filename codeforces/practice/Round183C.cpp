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

struct hashFunction
{
  size_t operator()(const pair<string , string> &p) const{
    size_t h1 = hash<string>{}(p.F);
    size_t h2 = hash<string>{}(p.S);
    return h1 ^ (h2 << 1);
  }
};

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

    int tc1, tc2;
    string pl1 = "", pl2 = "";

    cin >> tc1;
    fo (i, tc1) {
        int num;
        cin >> num;
        num = num - 1;
        pl1 += num;
    }

    cin >> tc2;
    fo (i, tc2) {
        int num;
        cin >> num;
        num = num - 1;
        pl2 += num;
    }

    unordered_set<pair<string, string>, hashFunction> vis;
    vis.insert({pl1, pl2});

    bool possible = true;
    int moves = 0;

    while (possible) {
        moves++;
        string c1 = pl1.substr(0, 1);
        string c2 = pl2.substr(0, 1);
        
        if (c1.compare(c2) < 0) {
            pl1 = pl1.substr(1);
            pl2 = pl2.substr(1) + c1 + c2;
        } else {
            pl1 = pl1.substr(1) + c2 + c1;
            pl2 = pl2.substr(1);
        }

        if (pl1.size() == 0) {
            cout << moves << " 2";
            possible = false;
        } else if (pl2.size() == 0) {
            cout << moves << " 1";
            possible = false;
        }

        pair<string, string> state = {pl1, pl2};

        if (vis.find(state) != vis.end()) {
            cout << "-1";
            possible = false;
        } else {
            vis.insert(state);
        }
        
    }

    return 0;
}
