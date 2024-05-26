#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

int distinct = 0;
int freq[10000100];

int get_less_than_eq(int k) {
  long long ans = 0;
  // pointers
  int tail = 0, head = -1;

  // magic starts!
  while (tail < n) {
    // eat as many elements as possible
    while (head + 1 < n && (distinct + ((freq[x] == 0) ? 1 : 0) <= k)) {
      head++;
      // insert
      freq[arr[head]]++;
      if (freq[arr[head]] == 1)
        distinct++;
    }
    // save the best for the tail
    long long len = (head - tail + 1);
    ans += len * (len + 1) / 2;

    // tail increamnet;
    if (tail <= head) {
      // erase
      freq[arr[tail]]--;
      if (freq[arr[tail]] == 0)
        distinct--;

      tail++;
    } else {
      tail++;
      head = tail - 1;
    }
  }

  return ans;
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << get_less_than_eq(k) - get_less_than_eq(k - 1) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}