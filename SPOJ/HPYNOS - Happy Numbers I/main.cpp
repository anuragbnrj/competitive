#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    char a[10];
    int i=0,b=0,x,c=1;
    gets(a);

    while(a[i]!='\0')
    {
            b= b + (a[i] - 48) * (a[i]-48);
            i++;
    }

    while(b>9)
    {     x=0;
        while(b>0)
        {    x=(b%10) * (b%10) +x;
             b=b/10;

        }
        b=x;
        c++;
    }
    if(b==1)
        printf("%d",c);
    else
        printf("-1");

    return 0;


}
