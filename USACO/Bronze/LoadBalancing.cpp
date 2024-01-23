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


int getNumberOfMaxCowsInRegion(vpii locs, int xline, int yline) {
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;

    fo(i, 0, locs.size()) {
        int x = locs[i].F;
        int y = locs[i].S;

        if (x < xline && y < yline) {
            q1++;
        } else if (x > xline && y < yline) {
            q2++;
        } else if (x < xline && y > yline) {
            q3++;
        } else {
            q4++;
        }
    }

    return(max(q1, max(q2 , max(q3, q4))));
}


int main() {
    // freopen("balancing.in", "r", stdin);
    // freopen("balancing.out", "w", stdout);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, b;
    cin >> n >> b;

    vpii locs;
    vi xlocs;
    vi ylocs;

    fo(i, 0, n) {
        int x, y;
        cin >> x >> y;

        locs.push_back({x, y});
        xlocs.push_back(x);
        ylocs.push_back(y);
    }

    sort(xlocs.begin(), xlocs.end());
    sort(ylocs.begin(), ylocs.end());

    vi xlines;
    vi ylines;

    if (n % 2 == 0) {
        int med1 = (n / 2) - 1;
        int med2 = (n / 2);

        xlines.push_back(xlocs[med1] - 1);
        xlines.push_back(xlocs[med1] + 1);
        xlines.push_back(xlocs[med2] - 1);
        xlines.push_back(xlocs[med2] + 1);


        ylines.push_back(ylocs[med1] - 1);
        ylines.push_back(ylocs[med1] + 1);
        ylines.push_back(ylocs[med2] - 1);
        ylines.push_back(ylocs[med2] + 1);
    } else {
        int med = (n / 2);

        xlines.push_back(xlocs[med] - 1);
        xlines.push_back(xlocs[med] + 1);

        ylines.push_back(ylocs[med] - 1);
        ylines.push_back(ylocs[med] + 1);
    }

    int maxCows = INT_MAX;
    fo(i, 0, xlines.size()) {
        fo(j, 0, ylines.size()) {
            maxCows = min(maxCows, getNumberOfMaxCowsInRegion(locs, xlines[i], ylines[j]));
        }
    }
    
    cout << maxCows << endl;

    return 0;
}
