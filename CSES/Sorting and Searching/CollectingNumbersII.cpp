#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 2, 0);
    vector<int> inverted(n + 2, false);
    unordered_map<int, int> pos;
    pos[0] = 0;
    pos[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }


    int rounds = 1;
    for (int i = 1; i <= n; i++) {
        int curr = arr[i];
        int prev = curr - 1;

        if (pos[curr] < pos[prev]) {
            rounds += 1;
            inverted[curr] = true;
        }
    }


    for (int i = 1; i <= m; i++) {
        int pos1, pos2;
        cin >> pos1 >> pos2;

        int num1 = arr[pos1];
        int num2 = arr[pos2];

        arr[pos2] = num1;
        arr[pos1] = num2;

        pos[num1] = pos2;
        pos[num2] = pos1;


        unordered_set<int> consider;
        consider.insert(num1);
        consider.insert(num1 + 1);
        consider.insert(num2);
        consider.insert(num2 + 1);

        for (auto el : consider) {
            int curr = el;
            int prev = el - 1;

            if (inverted[curr]) {
                if (pos[curr] < pos[prev]) {
                    // rounds += 1;
                    inverted[curr] = true;
                } else {
                    rounds -= 1;
                    inverted[curr] = false;
                }
            } else {
                if (pos[curr] < pos[prev]) {
                    rounds += 1;
                    inverted[curr] = true;
                } else {
                    // rounds -= 1;
                    inverted[curr] = false;
                }
            }
        }


        cout << rounds << endl;
    }

    return 0;
}
