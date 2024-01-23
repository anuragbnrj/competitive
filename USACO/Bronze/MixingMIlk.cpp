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

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    // int n;
    // cin >> n;

    ll cap[3];
    ll mlk[3];

    cin >> cap[0] >> mlk[0];
    cin >> cap[1] >> mlk[1];
    cin >> cap[2] >> mlk[2];
    foeq(i, 1, 100) {
        if (i % 3 == 1) {
            int tot = mlk[0] + mlk [1];

            if (tot > cap[1]) {
                ll pour = cap[1] - mlk[1];
                mlk[1] += pour;
                mlk[0] -= pour;
            } else {
                mlk[1] += mlk[0];
                mlk[0] = 0;
            }
        }else if (i % 3 == 2) {
            int tot = mlk[1] + mlk [2];

            if (tot > cap[2]) {
                ll pour = cap[2] - mlk[2];
                mlk[2] += pour;
                mlk[1] -= pour;
            } else {
                mlk[2] += mlk[1];
                mlk[1] = 0;
            }
        } else {
            int tot = mlk[2] + mlk [0];

            if (tot > cap[0]) {
                ll pour = cap[0] - mlk[0];
                mlk[0] += pour;
                mlk[2] -= pour;
            } else {
                mlk[0] += mlk[2];
                mlk[2] = 0;
            }
        }
    }

    cout << mlk[0] << endl << mlk[1] << endl << mlk[2] << endl;

    return 0;
}
