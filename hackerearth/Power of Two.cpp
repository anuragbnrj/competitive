#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int x)
{
    return (x && !(x & (x - 1)));
}

int main()
{
    int t, i, flag, ai;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        flag=0;
        for(i=0;i<n;i++)
        {
            scanf("%d", &ai);
            if(flag==0)
            {
                if(isPowerOfTwo(ai)){flag=1;}
            }
        }
        if(flag==1){printf("YES\n");}
        else {printf("NO\n");}
    }
    return 0;
}
