#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

int arr[100005];
int temp[100005];

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (k > n) {
		k = k % n;
	}

	// for (int i = 0; i < k; i++) {
	// 	temp[i] = arr[n - 1 - i];
	// }

	// for (int i = n - 1; i >= k; i--) {
	// 	arr[i] = arr[i - k];
	// }

	// for (int i = k; i >= 0; i--) {
	// 	arr[k - i] = temp[i];
	// }

	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

    for (int i = n - k; i < n; i++) {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < n - k; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    
	while (t--) {
		solve();
	}  

    return 0;
}
