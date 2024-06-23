// Problem Link:

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;

struct Node {
    Node *child[26];
    int prefix;
    vector<string> wend;

    Node() {
        prefix = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

struct Trie {
    Node *root;

    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node *curr = root;
        
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';

            if (curr->child[x] == nullptr) {
                curr->child[x] = new Node();
            }

            curr = curr->child[x];
            curr->prefix++;
        }
        curr->wend.push_back(s);
    }
};

void solve() {
    int n;
    cin >> n;
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
