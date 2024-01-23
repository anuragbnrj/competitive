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


int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    string str;
    cin >> str;

    unordered_set<char> done;

    int count = 0;
    fo(i, 0, str.length()) {
        char curr = str[i];

        bool bwn[26];
        fill_n(bwn, 26, false);
        fo(j, i + 1, str.length()) {
            char tmp = str[j];
            if (tmp == curr) {
                break;
            } else {
                bwn[tmp - 'A'] = !bwn[tmp - 'A'];
            }
        }

        fo(j, 0, 26) {
            if (bwn[j] && done.find((char) ('A' + j)) == done.end() ) {
                count++;
            }
        }

        done.insert(curr);
    }

    cout << count << endl;

    return 0;
}
