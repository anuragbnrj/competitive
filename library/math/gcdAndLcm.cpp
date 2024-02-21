#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

// GCD / HCF
int gcdRec(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int gcdRec2(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int gcdInt(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int gcdFast(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// LCM
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}
