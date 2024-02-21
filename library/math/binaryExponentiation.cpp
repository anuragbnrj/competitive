#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;


long long binPowRecursive(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binPowRecursive(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}


long long binPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


long long binPowMod(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a =(a * a) % m;
        b >>= 1;
    }
    return res;
}
