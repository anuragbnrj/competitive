#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long num, res = 0, pwr = 0;
	scanf("%lld" , &num);

	while (num > 9) {
		int rem = num % 10;

		if (rem > 4) {
			rem = 9 - rem;
		}

		res = (rem * pow(10, pwr++)) + res;

		num /= 10;

	}

	if (num == 9 || num < 5) {
		res = (num * pow(10, pwr++)) + res;
	} else {
		res = (9 - num) * pow(10, pwr++) + res;
	}

	cout << res;


	return 0;
}
