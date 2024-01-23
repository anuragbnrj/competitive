#include<cmath>
#include<cstdio>

using namespace std;

unsigned long long eval(int n);
int C, T, coefs[30], d, k;

int main()
{
    int i=0,n=0,sum=0;
    scanf("%d", &C);
    while(C--)
    {
        scanf("%d", &T);
        for(i = 0; i <= T; i++)
            {scanf("%d ", &coefs[i]);}
        scanf("%d",&d);
        scanf("%d",&k);
        for(n=1;;n++)
        {
            sum=sum+n*d;
            if(sum >= k){break;}
        }
        printf("%llu\n", eval(n));
        sum =0;
    }
    return 0;
}

unsigned long long eval(int n)
{
    unsigned long long t=0;
    for(int i=0;i<=T;i++)
    {
       t+= coefs[i]*pow(n,i);
    }
    return t;
}


