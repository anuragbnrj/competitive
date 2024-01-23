#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d" , &n);

	int arr[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int res = INT_MIN;
	for (int i = 0; i < n; i++) {

		int l = i;
		int cntLft = 0;
		while (l > 0 && arr[l - 1] <= arr[l]) {
			cntLft++;
			l--;
		}

		int r = i;
		int cntRight = 0;
		while (r < n - 1 && arr[r] >= arr[r + 1]) {
			cntRight++;
			r++;
		}

		res = max(res, cntLft + cntRight + 1);
	}

	cout << res;


	return 0;
}
