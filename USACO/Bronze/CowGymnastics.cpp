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

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required

    int k;
    cin >> k;

    int n;
    cin >> n;

    vector<vector<int>> inp(k, vector<int>(n)), perf(k, vector<int>(n));


    fo(i, 0, k) {
        fo(j, 0, n) {
            cin >> inp[i][j];
        }
    }

    fo(i, 0, k) {
        fo(j, 0, n) {
            perf[i][inp[i][j] - 1] = j;
        }
    }

    int numOfPairs = 0;
    fo(i, 0, n - 1) {
        fo(a, i + 1, n) {
            int c1 = inp[0][i] - 1;
            int c2 = inp[0][a] - 1;

            int won = 1;

            fo(j, 1, k) { 
                if (perf[j][c1] < perf[j][c2]) {
                    won++;
                }
            }

            if (won == k) {
                numOfPairs++;
            }
        }
    }

    cout << numOfPairs << endl;
    return 0;
}
