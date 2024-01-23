#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int MAX_NODE;

int BinSrc(int node, int balls)
{
    int left = node * 2, right = left + 1;
    if (left<MAX_NODE && right<MAX_NODE)
    {
        if (balls%2==0) BinSrc(right, balls/2);
        else BinSrc(left, balls/2 + 1);
    }
    else return node;
}

int main()
{
    int T, D, I,dummy;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &D, &I);
        MAX_NODE = pow(2.0, D);
        printf("%d\n", BinSrc(1, I));
    }
    cin>>dummy;
    return 0;
}
