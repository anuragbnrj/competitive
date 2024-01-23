#include <bits/stdc++.h>

using namespace std;

void solve() {

	int k, n;
	scanf("%d %d", &k, &n);

	int curr = 1, diff = 0;

	for (int i = 1; i <= k; i++) {
		cout << curr << " ";

		if (n - (curr + diff + 1) >= (k - i - 1) ) {
			diff++;
			curr += diff;
		} else {
			curr += 1;
		}

	}

	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d" , &t);
	while (t--) {
		solve();
	}

	return 0;
}
