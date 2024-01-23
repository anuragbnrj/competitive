#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k, l, c, d, p, nl, np;
	scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);

	int dr, li, sa;
	dr = (k * l) / (n * nl);
	li = (c * d) / (n);
	sa = p / (n * np);

	int res = min(dr, min(li, sa));

	cout << res;

	return 0;
}

