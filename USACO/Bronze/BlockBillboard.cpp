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
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    // int n;
    // cin >> n;

    int ax1, ay1, ax2, ay2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;

    int bx1, by1, bx2, by2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    int tx1, ty1, tx2, ty2;
    cin >> tx1 >> ty1 >> tx2 >> ty2;


    int ix, iy, iar, tot;
    ix = max(min(ax2, tx2) - max(ax1, tx1), 0);
    iy = max(min(ay2, ty2) - max(ay1, ty1), 0);
    iar = ix * iy;
    int aar = (ax2 - ax1) * (ay2 - ay1);
    tot += (aar - iar);

    
    ix = max(min(bx2, tx2) - max(bx1, tx1), 0);
    iy = max(min(by2, ty2) - max(by1, ty1), 0);
    iar = ix * iy;
    int bar = (bx2 - bx1) * (by2 - by1);
    tot += (bar - iar);


    cout << tot << endl;
}
