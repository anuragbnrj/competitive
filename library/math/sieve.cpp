#include <bits/stdc++.h>

using namespace std;


vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    return is_prime;
}
