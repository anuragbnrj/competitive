#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    if(c!=0)
    {
        if(((b-a)%c==0) && ((b-a)/c)> 0 )
            printf("YES\n");
        else
            printf("NO");
    }
    if(c==0)
    {
        if(a==b)
            printf("YES\n");
        else
            printf("NO");
    }
    return 0;
}
