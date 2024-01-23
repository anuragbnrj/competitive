#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void initialize();
int root(int);
void weighted_union(int,int);
bool find(int,int);
long long kruskal();

const int MAX = 1e4 + 5;
int Arr[MAX],size[MAX], nodes, edges;
vector <pair<int , pair<int,int> > > g;


void initialize()
{
    for(int i=1;i<=nodes;i++)
    {
        Arr[ i ] = i ;
        size[ i ] = 1;
    }
}
void weighted_union(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }
}
int root(int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
        i = Arr[ i ];
    }
    return i;
}
bool find(int A,int B)
{
    if( root(A)==root(B) )
    return true;
    else
    return false;
}


long long kruskal()
{
    long long minimumCost = 0;
    initialize();
    for(int i = 0;i < edges;i++)
    {
        int u, v,cost;
        u = g[i].second.first;
        v = g[i].second.second;
        cost = g[i].first;
        if(!find(u,v))
        {
            minimumCost += cost;
            weighted_union(u, v);
        }
    }
    return minimumCost;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,weight,pr;
        long long minimumCost;
        cin>>pr;
        cin>>nodes ;
        cin>>edges;
        for(int i = 0;i < edges;++i)
        {
            cin >> x >> y >> weight;
            g.push_back(make_pair(weight, make_pair(x, y)));
        }
        sort(g.begin(),g.end());
        minimumCost = kruskal();
        cout << (pr*minimumCost) << endl;
    }
    return 0;
}
