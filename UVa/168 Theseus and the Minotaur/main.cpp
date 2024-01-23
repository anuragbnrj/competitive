#include <stdio.h>
#include <string.h>

int g[26][105], gt[105], K;
int candle[26], found, putorder[10005], pidx;

void dfs(int M, int T, int step)

int main()
{
    char s[1024];
    int i, x , y;
    while(gets(s))
    {
        if(s[0] == '#') break;
        memset(gt, 0, sizeof(gt));
        for(i = 0; s[i]; i++)
        {
            x = s[i]-'A', i++, i++;
            while(s[i] != ';' && s[i] != '.')
            {
                y = s[i]-'A';
                i++;
                g[x][gt[x]++] = y;
            }
            if(s[i] == '.') break;
        }
        char M[20], T[20];
        sscanf(s+i+1, "%s %s %d", M, T, &K);
        memset(candle, 0, sizeof(candle));
        found = 0, pidx = 0;
        dfs(M[0]-'A', T[0]-'A', 1);
    }
    return 0;
}
