// Problem Link: https://www.codechef.com/practice/course/zco-inoi-problems/ZCOPRAC/problems/ZCO12003

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> st;

    int maxRound = 0;
    int ctr = 0;
    bool ctrStart = false;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
       
        if (num == 1) {
            ctrStart = true;
        }

        if (ctrStart) {
            if (num == 1 || num == 3) {
                st.push(num);
                ctr++;
            } else if (num == 4) {
                st.pop();
                ctr++;
            } else {
                st.pop();
                ctr++;
                if (st.size() == 0) {
                    maxRound = max(maxRound, ctr);
                    ctrStart = false;
                    ctr = 0;
                }
            }
        }
    }

    int maxSquare = 0;
    ctr = 0;
    ctrStart = false;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
       
        if (num == 3) {
            ctrStart = true;
        }

        if (ctrStart) {
            if (num == 1 || num == 3) {
                st.push(num);
                ctr++;
            } else if (num == 2) {
                st.pop();
                ctr++;
            } else {
                st.pop();
                ctr++;
                if (st.size() == 0) {
                    maxSquare = max(maxSquare, ctr);
                    ctrStart = false;
                    ctr = 0;
                }
            }
        }
    }

    int maxAltDepth = 0, currAltDepth = 0;
    for (int i = 0; i < n; i++) {
        int curr = arr[i];

        if (curr == 1 || curr == 3) {
            if (st.empty() || st.top() != curr) {
                currAltDepth++;
            }
            st.push(curr);
            maxAltDepth = max(maxAltDepth, currAltDepth);
        } else { // case: curr == 2 || curr == 4
            int top = st.top();
            st.pop();
            if (st.empty() || top != st.top()) {
                currAltDepth--;
            }
        }
        
    }

    cout << maxAltDepth << " " << maxRound << " " << maxSquare << endl;
}  

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve(); 

    // int t; 
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}
