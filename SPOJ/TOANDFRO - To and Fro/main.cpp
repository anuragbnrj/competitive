#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    while(1)
    {
    int k=0,col=0,row=0,i=0,j=0,t=0;
    scanf("%d",&col);

    if(col==0)
        break;

    char enc[205];
    scanf("%s",enc);

    while(enc[k]!= '\0')
    {

        k++;
    }

    row=k/col;
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            if(j%2==0)
             {
                 t=col*j+i;
                 printf("%c",enc[t]);
             }
            else
            {
                t=col*(j+1)-(i+1) ;
                printf("%c",(char)enc[t]);
            }
        }
    }
    printf("\n");
    }

    return 0;
}
