#include <cstdio>
using namespace std;

int main()
{
    int t, num;
    scanf("%d", &t);
    while(t--)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if( (b-a) == 1)
        {
            printf("%lld\n", (a&b) );
        }
        else
        {
            if( (b-1)%2==0)
            {
                printf("%lld\n", (b-1));
            }
            else
            {
                printf("%lld\n", (b-2));
            }
        }
    }
    return 0;
}
