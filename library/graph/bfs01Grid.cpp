// Problem Link: https://maang.in/problems/One-Piece-902?resourceUrl=cs99-cp522-pl3553-rs902

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
int INF = 1e9;

bool isValid(int rows, int cols, int r, int c) {
    if (r < 0 || rows <= r) {
        return false;
    }

    if (c < 0 || cols <= c) {
        return false;
    }

    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> grid[r][c];
        }
    }

    int dr[] = {0, 0, 0, 1, -1};
    int dc[] = {0, 1, -1, 0, 0};
    
    deque<pair<int, int>> dq;
    vector<vector<int>> cost(n, vector<int>(m, INF));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    dq.push_front({0, 0});
    cost[0][0] = 0;

    while (!dq.empty()) {
        auto front = dq.front();
        dq.pop_front();
        int r = front.first;
        int c = front.second;

        if (visited[r][c]) continue;
        visited[r][c] = 1;

        for (int i = 1; i <= 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            int weight = 1;
            if (i == grid[r][c]) {
                weight = 0;
            }

            if (isValid(n, m, nr, nc)) {
                if (cost[nr][nc] > cost[r][c] + weight) {
                    cost[nr][nc] = cost[r][c] + weight;

                    if (weight == 1) {
                        dq.push_back({nr, nc});
                    } else {
                        dq.push_front({nr, nc});
                    }
                }

            }
        }

    }

    cout << cost[n - 1][m - 1] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
