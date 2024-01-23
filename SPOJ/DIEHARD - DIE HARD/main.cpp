#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int h,a,i,ti=0;
        scanf("%d %d",&h,&a);
        for(i=1;;i++)
        {
            if(h<=0 || a<=0)
            {
                break;
            }
            ti++;
            if(ti%2==1)
            {
                h+=3;
                a+=2;
            }
            else
            {
                if(h>20 && a>10)
                {
                    h-=5;
                    a-=10;
                }
                else if(h>20 && a<=10)
                {
                    h-=20;
                    a+=5;
                }
                else
                {
                    h-=5;
                    a-=10;
                }
            }
        }
        printf("%d\n",(ti-1));

    }
    return 0;
}
