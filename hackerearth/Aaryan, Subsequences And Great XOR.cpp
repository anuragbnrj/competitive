#include <bits/stdc++.h>
using namespace std;

int bt[40];

int main()
{
    int n, i, j;
    cin>>n;
    int num, res=0;
    for(i=0;i<40;i++)
    {
        bt[i]=0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d", &num);
        for(j=0;j<40;j++)
        {
            if( num & (1<<j) )
                bt[j]=1;
        }
    }
    for(i=0;i<40;i++)
    {
        res=res+((long)pow(2,i)*bt[i]);
    }
    printf("%d\n", res);
    return 0;
}
