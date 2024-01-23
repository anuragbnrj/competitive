#include <cstdio>
using namespace std;

int BIT[100005], a[100005], n, q;
void update(int x, int val)
{
      for(; x <= n; x += x&-x)
        BIT[x] += val;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
     int i, x, y, d, ans;
     scanf("%d", &n);
     for(i=1;i<=n;i++)
     {
         scanf("%d", &a[i]);
         if(a[i]%2==1)
            update(i,1);
     }
     scanf("%d", &q);
     for(i=1;i<=q;i++)
     {
         scanf("%d %d %d", &d, &x, &y);
         if(d==0)
         {
             if(a[x]%2==1)
             {
                 update(x,-1);
                 a[x]=y;
                 if(y%2==1)
                    update(x,1);
             }
             else
             {
                 a[x]=y;
                 if(y%2==1)
                    update(x,1);
             }
         }
         if(d==2)
         {
             ans = query(y) - (x == 1 ? 0 : query(x - 1));
             printf("%d\n", ans);
         }
         if(d==1)
         {
             ans = query(y) - (x == 1 ? 0 : query(x - 1));
             ans = (y-x+1) - ans;
             printf("%d\n", ans);
         }
     }

}
