#include <bits/stdc++.h>
using namespace std;

int main()
{
    int xi, yi, di, n, i, k=0, c=1, ar[100005];
    cin>>n;
    while(n--)
    {
        cin>>xi>>yi>>di;
        for(i=xi;i<=(xi+di);i++)
        {
            ar[k++]=i;
        }
    }
    sort(ar,ar+k);
    for(i=1;i<k;i++)
    {
        if(ar[i]!=ar[i-1])c++;
    }

    cout << c << endl;
    return 0;
}
