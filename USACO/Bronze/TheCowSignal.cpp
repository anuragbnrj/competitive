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

void solve() {
    
} 

int main() {

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    // int n;
    // cin >> n;

    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<char>> sig(m, vector<char>(n)); 
    
    fo(i, 0, m) {
        fo(j, 0, n) {
            cin >> sig[i][j];
        }
    }

    vector<vector<char>> res(m*k, vector<char>(n*k));
    fo(i, 0, m) {
        fo(j, 0, n) {
            char ch = sig[i][j];

            fo(r, i * k, i * k + k) {
                fo (c, j * k, j * k + k) {
                    res[r][c] = ch;
                }
            }
        }
    }

    fo(r, 0, m * k) {
        fo(c, 0, n * k) {
            cout << res[r][c];
        }

        cout << endl;
    }

    return 0;
}
