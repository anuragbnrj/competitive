#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    long int i,c=0,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if((i*j)>n)
                break;
            else
                c++;
        }
    }
    printf("%ld\n",c);
    return 0;
}
