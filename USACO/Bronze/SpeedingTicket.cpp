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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    // int n;
    // cin >> n;

    int n, m;

    cin >> n >> m;

    int arr[100];
    int len = 0;
    fo(i, 0, n) {
        int seg, spd;
        cin >> seg >> spd;
        int curr = seg;
        int limit = spd;

        for(int j = len; j < len + curr; j++) {
            arr[j] = limit;
        }
        len += curr;
    }


    int mx = INT_MIN;
    len = 0;
    fo(i, 0, m) {
        int seg, spd;
        cin >> seg >> spd;
        int curr = seg;
        for(int j = len; j < len + curr; j++) {
            if (spd > arr[j]) {
                mx = max(mx, spd - arr[j]);
            }
        }
        len += curr;
    }

    if (mx == INT_MIN) {
        cout << 0 << endl;
    } else {
        cout << mx << endl;
    }

}
