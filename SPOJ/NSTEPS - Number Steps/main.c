#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t=0;
    scanf("%d",&t);
    while(t--)
    {
        int x=0,y=0;
        scanf("%d %d",&x,&y);
        if((x==y)||(x==(y+2)))
        {
            if(y%2==0)
                printf("%d\n",(x+y));
            else
                printf("%d\n",(x+y-1));
        }
        else
            printf("No Number\n");
    }

    return 0;
}
