#include <vector>
using namespace std;

extern int n;

// n以下の素数を列挙
void sieve() {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p < n; ++p) {
        if (!isPrime[p]) continue;
        for (int q = 2*p; q <= n; q += p) {
            isPrime[q] = false;
        }
    }
}

// 1以上n以下の整数をすべて素因数分解
void range_sieve() {
    vector<bool> isPrime(n+1, true);
    vector<int> minFactor(n+1, -1);
    isPrime[0] = isPrime[1] = false;
    minFactor[1] = 1;
    for (int p = 2; p <= n; ++p) {
        if (!isPrime[p]) continue;
        minFactor[p] = p;
        for (int q = 2*p; q <= n; q += p) {
            isPrime[q] = false;
            if (minFactor[q] == -1) minFactor[q] = p;
        }
    }
    vector<vector<pair<int, int>>> factorized(n+1);
    for (int i = 2; i <= n; ++i) {
        int k = i;
        while (k > 1) {
            int p = minFactor[k];
            int exp = 0;
            while (minFactor[k] == p) {
                k /= p;
                ++exp;
            }
            factorized[i].emplace_back(p, exp);
        }
    }
}