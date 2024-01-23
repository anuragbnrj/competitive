#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX_N 2010
#define MAX_W 2010

int i, w, T, N, G, MW, V[MAX_N], W[MAX_N], C[MAX_N][MAX_W], ans;

int main()
{

    scanf("%d %d",&MW ,&N);
    for (i = 1; i<= N; i++)
      scanf("%d %d", &W[i], &V[i]);

    ans = 0;


      for (i = 0; i <= N;  i++) C[i][0] = 0;
      for (w = 0; w <= MW; w++) C[0][w] = 0;

      for (i = 1; i <= N; i++)
        for (w = 1; w <= MW; w++)
        {
          if (W[i] > w) C[i][w] = C[i - 1][w];
          else          C[i][w] = max(C[i - 1][w], V[i] + C[i - 1][w - W[i]]);
        }

      ans = C[N][MW];

    printf("%d\n", ans);

  return 0;
}


