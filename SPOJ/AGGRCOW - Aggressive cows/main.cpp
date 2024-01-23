#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100001;
const int INF = 1000000001;

int a[MAX];

bool possible(int n, int c, int dist)
{
	int i, put = 1, last = a[0];
	for(i = 1; i < n && put < c; i++)
    {
		if(a[i]-last >= dist)
		{
			put++;
			last = a[i];
		}
	}
	return (put == c);
}

int main()
{
	int t, n, i, c, maxdiff, mindiff, middiff, best;
	scanf("%d", &t);
	while(t--)
    {
		scanf("%d%d", &n, &c);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		maxdiff = INF;
		mindiff = best = 0;
		while(mindiff <= maxdiff)
		{
			middiff = (maxdiff + mindiff) >> 1;
			if(possible(n, c, middiff))
			{
				best= middiff;
				mindiff = middiff + 1;
			}
			else maxdiff = middiff - 1;
		}
		printf("%d\n", best);
	}
	return 0;
}
