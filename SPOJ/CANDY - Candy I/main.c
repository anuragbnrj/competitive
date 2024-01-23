#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==(-1))
            break;
        int *arr;
        arr=(int *)malloc(n*sizeof(int));
        int i=0,sum=0,k=0,cdy=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum=sum+arr[i];
        }
        if(sum%n!=0)
        {
           printf("-1\n");
        }
        else
        {
            cdy=sum/n;
            for(i=0;i<n;i++)
            {
               while(arr[i]!=cdy)
               {
                   if(arr[i]<cdy)
                   {
                       arr[i]=arr[i]+1;
                   }
                   else
                   {
                       arr[i]=arr[i]-1;
                   }
                   k++;
               }
            }
            printf("%d\n",(k/2));
        }
    }

    return 0;
}
