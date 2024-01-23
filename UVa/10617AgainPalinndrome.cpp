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


int solve(int beg_idx, int end_idx, string str) {
    if (beg_idx > end_idx) {
        return 0;
    }

    if (beg_idx == end_idx) {
        return 1;
    }

    char beg = str[beg_idx];
    char end = str[end_idx];

    if ( (end_idx - beg_idx == 1) && (beg == end)) {
        return 1;
    }


    int rm_beg = solve(beg_idx + 1, end_idx, str);
    int rm_end = solve(beg_idx, end_idx - 1, str);
    int rm_both = solve(beg_idx + 1, end_idx - 1, str);

    if (beg == end) {
        rm_both = rm_both * 2;
    }

    return rm_beg + rm_end + rm_both;
}



int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

    // for handling problems in which test cases are not required
    // int n;
    // cin >> n;

    
    //write code here

    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        int len = str.size();
        int res = solve(0, len - 1, str);
        cout << res << endl;
    }

    return 0;
}