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
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    int n;
    cin >> n;

    int arr[26]{0};

    fo(i, 0, n) {
        string w1; 
        string w2;
        cin >> w1 >> w2;

        unordered_map<char, int> m1, m2;

        fo(j, 0, w1.length()) {
            char ch = w1[j];
            m1[ch] += 1;
        }

        fo(j, 0, w2.length()) {
            char ch = w2[j];
            m2[ch] += 1;
        }

        fo(j, 0, 26) {
            arr[j] += max(m1['a' + j], m2['a' + j]);
        }
    }

    fo(j, 0, 26) { 
        cout << arr[j] << endl;
    }

    return 0;
}
