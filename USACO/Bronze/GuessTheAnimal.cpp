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
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector< pair< string, unordered_set<string> > > animals;
    unordered_map<string, int> traitCount;

    
    fo(i, 0, n) {
        string name;
        cin >> name;

        int numOfTraits;
        cin >> numOfTraits;

        unordered_set<string> traits;
        fo(j, 0, numOfTraits) {
            string trait;
            cin >> trait;
            traits.insert(trait);
        }

        animals.push_back({name, traits});
    }

    int maxYes = INT_MIN;
    fo(i, 0, n) {
        string nameA = animals[i].F;
        unordered_set<string> traitsA = animals[i].S;
        fo(j, 0, n) {
            int overlap = 0;
            if (i == j) {
                continue;
            }
            string nameB = animals[j].F;
            unordered_set<string> traitsB = animals[j].S; 

            for(auto it : traitsA) {
                if (traitsB.find(it) != traitsB.end()) {
                    overlap++;
                }
            }

            maxYes = max(maxYes, overlap + 1);
        }
    } 

    cout << maxYes << endl;
    return 0;
}
