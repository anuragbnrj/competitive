// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;


// Custom Comparator for multiset
struct cmp {
    bool operator() (const pair<int, ll> &p1, const pair<int, ll> &p2) const {
        if (p1.first < p2.first) {
            return true;
        } 

        if (p1.first == p2.first) {
            return p1.second > p2.second;
        }
        
    }
};

// How to print floor, ceil, and round of division without using floating point integers
void printFloorCeilRound() {
    int a, b;
    cout << "Enter 2 numbers" << endl;
    cin >> a >> b;

    // Floor:
    int floor = (a / b);
    cout << floor << endl;

    // Ceil:
    int ceil = (a + b - 1) / b;
    cout << ceil << endl;

    // Round:
    // ( (a / b) + (1 / 2) ) 
    int round = ((2 * a) + b) / (2 * b);
    cout << round << endl;



}

// How to take as input an entire line which contains spaces
void stringLineInput() {
    /*
    Input Example:
    2
    Hello, welcome to the event!
    How are you doing
    */

    int n;
    cin >> n;

    string temp;
    // to solve for dummy \n issue when  SWITCHING from cin to getline
    getline(cin, temp);

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
    }
    
}

// Printing of double precision integers
void doublePrecisionPrinting() {
    double avg = 0.13333333333333333333333333;

    // To print the exact amount of digits after decimal point
    // 7 digits
    // printf("%.7f \n", avg);
    cout << fixed << setprecision(7) << avg << endl;
} 

void solve() {
    
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
