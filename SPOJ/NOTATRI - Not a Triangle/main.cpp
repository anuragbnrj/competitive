using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
int N,temp,T,i,j,ans,k,inp[2020];
int main()
{
    bool changed;
    while (1)
    {
          scanf("%d",&N);
          if(N==0) break;
          ans=0;
          for( T=0;T<N;T++)
          {
                scanf("%d",&inp[T]);
          }
          sort(inp,inp+N);
          inp[N]=2000000;
          for (i=0;i<N;i++)
          {
              for (j=k=i+1;j<N;j++)
              {
                  while(inp[i]+inp[j]>=inp[k]) k++;
                  temp=N-k;
                  ans+=temp;
              }
          }
          printf("%d\n",ans);
    }
    return 0;
}
