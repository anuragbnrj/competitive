#include <bits/stdc++.h>

using namespace std;

// #define PI 3.1415926535897932384626
// #define mod 1000000007
// #define fo(i, st, end) for (int i = st; i < end; i++)
// #define foeq(i, st, end) for (int i = st; i <= end; i++)
// #define revfo(i, st, end) for (int i = st; i > end; i--)
// #define revfoeq(i, st, end) for (int i = st; i >= end; i--)
// #define foit(it, a) for (auto it = a.begin(); it != a.end(); it++)
// #define clr(x) memset(x, false, sizeof(x))
// #define all(x) x.begin(), x.end()
// #define sortall(x) sort(all(x))
// #define pb push_back
// #define mp make_pair
// #define F first
// #define S second
// #define deb(x) cout << #x << "=" << x << endl


// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pllll;
// typedef vector< int > vi;
// typedef vector< ll > vll;
// typedef vector< pii > vpii;
// typedef vector< pllll > vpllll;
// typedef vector< vi > vvi;
// typedef vector< vll > vvll;

vector<int> weights, values;
const int MAX = 2000 + 1;
int dp[MAX][MAX];


int knapsack(int idx, int remains) {
    if (idx == weights.size()) {
        return 0;
    }

    if (dp[idx][remains] != - 1) {
        return dp[idx][remains];
    }

    int choice1 = knapsack(idx + 1, remains);
    int choice2 = 0;

    if (weights[idx] <= remains) {
        choice2 = values[idx] + knapsack(idx + 1, remains - weights[idx]);
    }

    dp[idx][remains] = max(choice1, choice2);

    return dp[idx][remains];
}


int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    // int n;
    // cin >> n;

    int s, n;
    cin >> s >> n;


    for(int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;

        weights.push_back(weight);
        values.push_back(value);
    }

    cout << knapsack(0, s) << endl;

    return 0;
}
