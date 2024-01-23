#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int V,E;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind
{
    private:
        vi p, rank, setSize;
        int numSets;
    public:
        UnionFind(int N)
        {
            setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
            p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
        }
        int findSet(int i)
        {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j)
        {
            return findSet(i) == findSet(j);
        }
        void unionSet(int i, int j)
        {
            if (!isSameSet(i, j))
            {
                numSets--;
                int x = findSet(i),
                y = findSet(j);

                if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
                else
                {
                    p[x] = y; setSize[y] += setSize[x];
                    if (rank[x] == rank[y]) rank[y]++;
                }
            }
        }
        int numDisjointSets() { return numSets; }
        int sizeOfSet(int i) { return setSize[findSet(i)]; }
};



int main()
{
    cin>>V>>E;
    while(V!=0 && E!=0)
    {
        int u,v,w;
        long long totcost=0;
        vector< pair<int, ii> > EdgeList;
        for (int i = 0; i < E; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            totcost+=w;
            EdgeList.push_back(make_pair(w, ii(u, v)));

        }
        sort(EdgeList.begin(), EdgeList.end());

        long long mst_cost = 0;
        UnionFind UF(V);
        for (int i = 0; i < E; i++)
        {
            pair<int, ii> front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                mst_cost += front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
        }
        cout << totcost-mst_cost<< endl;
        cin>>V>>E;
    }
    return 0;
}
