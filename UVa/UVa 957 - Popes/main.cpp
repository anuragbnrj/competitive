#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int y,p,popeyr[100001],i,el,mx=0,low,up,mid,mxst=0,mxend=0;
    while ( scanf ("%d", &y) != EOF )
    {
        scanf("%d",&p);
        for(i=0;i<p;i++)
        {
            scanf("%d",&popeyr[i]);
        }
        for(i=0;i<p;i++)
        {
            low=i+1;up=p-1;
            el=popeyr[i]+y-1;
            while(low<up)
            {
                mid=(low+up)/2;
                if(popeyr[mid]>el){up=mid;}
                else{low=mid+1;}
            }
            if((up-i)>mx){mx=up-i;mxst=popeyr[i];mxend=popeyr[up-1];}
        }
        printf("%d %d %d\n",mx,mxst,mxend);
    }

    return 0;
}
