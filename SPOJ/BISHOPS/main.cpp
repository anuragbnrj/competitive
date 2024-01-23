#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{

    char n[110];
    while(scanf("%s",&n)!=EOF)
    {
        int i,num[110],c=0,sum[110]={0},c2=0,x=0,carry=0,len=0,k=0,d=0;
        char *ptr,r[110];
         len = strlen(n);
         if(strcmp(n,"1")==0)
         {
             printf("1\n");
             continue;
         }
         if(strcmp(n,"0")==0)
         {
             printf("0\n");
             continue;
         }


        for (k =len - 1, d = 0; k >= 0; k--, d++)
        r[d] = n[k];

        r[d] = '\0';
        ptr = r;
        while(*ptr)
        {
            num[c] = *ptr++ - 48;
            c++;

        }
        for(i=0;i<c;i++)
        {
            x=num[i]*2+carry;
            sum[c2]=x%10;
            c2++;
            carry=x/10;
        }
        sum[c2]=carry;
        int a[110]={0};
        a[0]=2;
        for (i = 0; i <=c2; i++)
        {
            if (sum[i] < 0)
            {
                sum[i+1]--;
                sum[i] += 10;
            }

            int temp = sum[i] - a[i];
            if (temp < 0)
            {
                temp = 10 + temp;
                sum[i+1]--;
            }
            sum[i] = temp;
        }
        if (sum[c2]==0)
        {
            c2--;
        }
        for(i=c2;i>=0;i--)
        {
            printf("%d",sum[i]);
        }
        printf("\n");


    }
    return 0;
}
