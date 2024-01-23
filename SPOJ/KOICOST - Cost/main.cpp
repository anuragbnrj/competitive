#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

void initialize(int);
void weighted_union(int,int);
int root(int);
bool find(int,int);

vector <pair<int , pair<int,int> > > g;
int Arr[100005];
long long cc,sum,size[100005];



void initialize(int N)
{
    for(int i=1;i<=N;i++)
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
        cc+=size[root_B]*size[root_A];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        cc+=size[root_B]*size[root_A];
        size[root_A] += size[root_B];
    }
}
int root(int i)
{
    while(Arr[ i ] != i)
    {
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




int main()
{
    int m,n,u,v,w,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
       scanf("%d %d %d", &u, &v, &w);
       g.push_back(make_pair(w,make_pair(u,v)));
    }
    sort(g.begin(),g.end());
    reverse(g.begin(),g.end());
    initialize(n);
    cc=0;sum=0;

    for(i=0;i<m;i++)
    {

        u=g[i].second.first;
        v=g[i].second.second;
        if(find(u,v))
        {
            sum=(sum+cc*g[i].first)%1000000000;
        }
        else
        {
            weighted_union(u,v);
            sum=(sum+cc*g[i].first)%1000000000;
        }
    }
    printf("%lld",sum);
    return 0;
}
