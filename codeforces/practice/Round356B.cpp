#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, a;
	scanf("%d %d" , &n, &a);
	int c[n];

	cout << "Hello";

	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	int l = a - 1, r = a - 1;
	int tot = 0;
	while (l >= 0 && r <= (n - 1)) {
		if (c[l] == 1 && c[r] == 1) {
			tot += (l == r) ? 1 : 2;
		}
		l--;
		r++;
	}

	while (l >= 0) {
		if (c[l] == 1) {
			tot++;
		}
		l--;
	}

	while (r <= (n - 1)) {
		if (c[r] == 1) {
			tot++;
		}
		r++;
	}

	cout << tot;

	return 0;
}
