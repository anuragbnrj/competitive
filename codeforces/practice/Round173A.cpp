#include <bits/stdc++.h>


using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int lines;
	cin >> lines;

	int res = 0;

	while (lines--) {
		string line;

		cin >> line;

		if (line[0] == '+' || line[2] == '+') {
			res++;
		} else {
			res--;
		}

	}
	cout << res;

	return 0;
}