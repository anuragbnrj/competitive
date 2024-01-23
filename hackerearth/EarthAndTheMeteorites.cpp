#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, q, i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        int x1, y1, xc=0, yc=0, xmx=0, xmn=99999999, ymx=0,ymn=99999999;
        set<int> x,y;
        x.insert(1);
        y.insert(1);
        x.insert(n);
        y.insert(m);
        for(i=0 ; i<q ; i++)
        {
            cin>>x1>>y1;
            x.insert(x1);
            y.insert(y1);
        }
        xc=x.size()-1; yc=y.size()-1;
        set<int>::iterator it1=x.begin();
        set<int>::iterator it2=x.begin();
        it2++;
        for(;it2!=x.end();it1++,it2++)
        {
            xmx=max(xmx,*it2-*it1);
            xmn=min(xmn,*it2-*it1);
        }
        it1=y.begin();
        it2=y.begin();
        it2++;
        for(;it2!=y.end();it1++,it2++)
        {
            ymx=max(ymx,*it2-*it1);
            ymn=min(ymn,*it2-*it1);
        }

        cout<<1LL*xc*yc<<" "<<1LL*xmn*ymn<<" "<<1LL*xmx*ymx<<endl;
    }
    return 0;
}
