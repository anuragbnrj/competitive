// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

class DisjointSet {
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        // Done to handle cases for 1-based indexing as well
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pU = findUltimateParent(u);
        int pV = findUltimateParent(v);
        if (pU == pV) {
            return;
        }

        if (rank[pU] == rank[pV]) {
            parent[pU] = pV;
            rank[pV]++;
        } else if (rank[pU] <= rank[pV]) {
            parent[pU] = pV;
        } else {
           parent[pV] = pU;
        }
    }

    void unionBySize(int u, int v) {
        int pU = findUltimateParent(u);
        int pV = findUltimateParent(v);
        if (pU == pV) {
            return;
        }

        if (size[pU] == size[pV]) {
            parent[pU] = pV;
            size[pV] += size[pU];
        } else if (size[pU] < size[pV]) {
            parent[pU] = pV;
            size[pV] += size[pU];
        } else {
            parent[pV] = pU;
            size[pU] += size[pV];
        }
    }

    int findDistinctParents(int n) {
        set<int> parents;
        for (int i = 0; i < n; i++) {
            int parent = findUltimateParent(i);
            parents.insert(parent);
        }

        return parents.size();
    }

};

void solve() {
    int n;
    cin >> n;

}  

int main() {
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


