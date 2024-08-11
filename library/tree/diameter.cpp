// Problem Link:

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// #include "D:\workspace_cpp\competitive\library\debugging.h"

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// template <class T>
// using oset = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
//---- Debugger stdout ---- //
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}
//----------------- //

long double PI = acos(-1.0);
ll MOD = 1e9 + 7;
ll INFL = 1e18;
int INF = 1e9; 


class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
//         int n = edges1.size();
//         vector<vector<int>> graph1(n);
//         for (auto edge : edges1) {
//             int u = edge[0];
//             int v = edge[1];
//             graph1[u].push_back(v);
//             graph1[v].push_back(u);
//         }
        
//         int m = edges2.size();
//         vector<vector<int>> graph2(m);
//         for (auto edge : edges2) {
//             int u = edge[0];
//             int v = edge[1];
//             graph2[u].push_back(v);
//             graph2[v].push_back(u);
//         }
        
        int dia1 = treeDiameter(edges1);
        int dia2 = treeDiameter(edges2);
        
        int farthest1;
        if (dia1 % 2 == 0) {
            farthest1 = dia1 / 2;
        } else {
            farthest1 = (dia1 / 2) + 1;
        }
        
        int farthest2;
        if (dia2 % 2 == 0) {
            farthest2 = dia2 / 2;
        } else {
            farthest2 = (dia2 / 2) + 1;
        }
        
        int ans = max({dia1, dia2, farthest1 + farthest2 + 1});
        
        return ans;
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        pair<int, int> first_bfs = bfs(0, adj);
        
        pair<int, int> second_bfs = bfs(first_bfs.first, adj);

        return second_bfs.second;
    }
    

    pair<int, int> bfs(int start, const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> distance(n, -1);
        queue<int> q;

        q.push(start);
        distance[start] = 0;

        int farthest_node = start;
        int max_distance = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);

                    if (distance[neighbor] > max_distance) {
                        max_distance = distance[neighbor];
                        farthest_node = neighbor;
                    }
                }
            }
        }

        return {farthest_node, max_distance};
    }
    

};