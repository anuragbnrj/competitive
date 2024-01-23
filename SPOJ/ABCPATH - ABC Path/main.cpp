#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char mat[50][50];
int visited[50][50];
int countv=0;
int n,m;

void dfsTraversal(int row ,int col, int DepthNow)
{
     countv=max(DepthNow,countv);
     int rr[8]={-1,-1,-1,0,0,1,1,1};
     int cc[8]={-1,0,1,-1,1,-1,0,1};
     for(int i=0;i<8;++i)
     {
          int tempr=row+rr[i];
          int tempc=col+cc[i];
          if((tempr>=0 && tempr<n) && (tempc>=0 && tempc<m) && !visited[tempr][tempc])
          {
               if(mat[tempr][tempc]== mat[row][col] + 1)
               {
                    visited[tempr][tempc]=1;
                    dfsTraversal(tempr,tempc,DepthNow+1);
               }
          }
     }
}

int main()
{
     scanf("%d%d",&n,&m);
     int c=0;
     while(n && m)
     {
          countv=0;
          c++;
          for(int i=0;i<n;++i)
          {
               for(int j=0;j<m;++j)
               {
                    cin>>mat[i][j];
                    visited[i][j]=0;
               }
          }
          for(int i=0;i<n;++i)
          {
               for(int j=0;j<m;++j)
               {
                    if(mat[i][j]=='A')
                    {
                        memset(visited,0,sizeof(visited));
                        visited[i][j]=1;
                        dfsTraversal(i,j,1);
                    }
               }
          }
          printf("Case %d: %d\n",c,countv);
          scanf("%d%d",&n,&m);
     }
     return 0;
}
