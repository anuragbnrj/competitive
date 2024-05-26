// Problem Link: https://codeforces.com/contest/1889/problem/A
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define PI 3.1415926535897932384626
#define MOD 1000000007
 
typedef long long ll;
 
void solve() {
    int n;
    cin >> n;
 
    string s;
    cin >> s;
 
    int zeros = 0, ones = 0;
    for (char ch : s) {
        if (ch == '0') {
            zeros++;
        } else {
            ones++;
        }
    }
 
    if (zeros != ones) {
        cout << -1 << endl;
        return;
    }
 
    string temp = s;
    int beg = 0, end = n - 1;
    vector<int> positions;
    deque<char> characters(s.begin(), s.end());
 
    int pos = 0;
    while (!characters.empty()) {
        if (characters.front() != characters.back()) {
            characters.pop_front();
            characters.pop_back();
            pos++;
        } else {
            if (characters.front() == '0') {
                characters.push_back('0');
                characters.push_back('1');
                positions.push_back(n - pos);
            } else {
                characters.push_front('1');
                characters.push_front('0');
                positions.push_back(pos);
            }

            n += 2;
        }
    }
 
    cout << positions.size() << endl;
    for (int i = 0; i < (int)positions.size(); i++) {
        cout << positions[i] << " ";
    }
    cout << endl;
}  
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
 
    // solve(); 
    
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
