#include <bits/stdc++.h>
using namespace std;

vector< int > bsm;

int main()
{
    int t, i;
    scanf("%d", &t);
    while(t--)
    {
        long long n, m, bm=0;
        scanf("%lld %lld", &n, &m);
        bsm.clear();
        while(m>0)
        {
            if(m%2==1)
            {
                bsm.push_back(bm);
            }
            m=m>>1;
            bm++;
        }
        printf("(%lld<<%d)", n, bsm[bsm.size()-1]);
        for(i= bsm.size() - 2; i>=0;i--)
        {
            printf(" + (%lld<<%d)", n, bsm[i]);
        }
        printf("\n");
    }
    return 0;
}
