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

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<char>> spc(n, vector<char>(m)), plc(n, vector<char>(m));

    fo(i, 0, n) {
        fo(j, 0, m) {
            cin >> spc[i][j];
        }
    }

    fo(i, 0, n) {
        fo(j, 0, m) {
            cin >> plc[i][j];
        }
    }

    ll res = 0;
    fo(col, 0, m) {
        int arr[26]{0};
        bool flag = true;
        fo(row, 0, n) {
            arr[spc[row][col] - 'A']++;
        }

        fo(row, 0, n) {
            if (arr[plc[row][col] - 'A'] > 0) {
                flag = false;
                break;
            }
        }

        if (flag == true) {
            res++;
        }
    }

    ll res = (res) (res - 1) (res - 2) / 6;
    cout << res << endl;
    
    return 0;
}
