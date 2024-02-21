// correctly calculates a mod b even if a < 0
#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

int intMod(int a, ll m) {
  return (a % m + m) % m;
}
