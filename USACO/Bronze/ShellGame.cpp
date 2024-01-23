#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define mod 1000000007

// void solve(int n, vector<array<int, 3>> steps) {
//     int mxCorr = 0;
//     int cp;

//     for (int sp = 1; sp <= 3; sp++) {
//         int corr = 0;
//         cp = sp;
//         for (int i = 0; i < n; i++) {
//             if (steps[i][0] == cp) {
//                 cp = steps[i][1];
//             } else if (steps[i][1] == cp) {
//                 cp = steps[i][0];
//             }

//             if (steps[i][2] == cp) {
//                 corr++;
//             }
//         }

//         mxCorr = max(corr, mxCorr);
//     }

//     cout << mxCorr << endl;
// } 






void solve(int n, vector<vector<int>> &steps) {

    int res1 = 0;
    int res2 = 0; 
    int res3 = 0;

    int arr1[] {0, 1, 0, 0};
    int arr2[] {0, 0, 1, 0};
    int arr3[] {0, 0, 0, 1};

    for (int i = 0; i < steps.size(); i++) {
        int p1 = min(steps[i][0], steps[i][1]);
        int p2 = max(steps[i][0], steps[i][1]);
        int guess = steps[i][2];

        swap(arr1[p1], arr1[p2]);
        swap(arr2[p1], arr2[p2]);
        swap(arr3[p1], arr3[p2]);

        
        if (arr1[guess] == 1) {
            res1++;
        }
        if (arr2[guess] == 1) {
            res2++;
        }
        if (arr3[guess] == 1) {
            res3++;
        }   
    }

    cout << "Hello" << endl;
    cout << max({res1, res2, res3}) << endl;
    
}


int main() {

    // freopen("shell.in", "r", stdin);
    // freopen("shell.out", "w", stdout);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // for handling problems in which test cases are not required
    int n;
    cin >> n;

    vector<vector<int>> steps(n);

    for (int i = 0; i < n; i++) {
        vector<int> step(3);
        cin >> step[0] >> step[1] >> step[2];

        steps.push_back(step);
    }

    solve(n, steps);

    return 0;
}
