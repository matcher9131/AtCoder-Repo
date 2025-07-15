#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> isPrime(m+1, true);
    vector<int> minFactor(m+1, -1);
    isPrime[0] = isPrime[1] = false;
    minFactor[0] = minFactor[1] = 1;
    for (int p = 2; p <= m; ++p) {
        if (!isPrime[p]) continue;
        minFactor[p] = p;
        for (int q = 2*p; q <= m; q += p) {
            isPrime[q] = false;
            if (minFactor[q] == -1) minFactor[q] = p;
        }
    }
    vector<vector<pair<int, int>>> factorized(m+1);
    for (int i = 2; i <= m; ++i) {
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

    vector<mint> factorial(n+20);
    factorial[0] = 1;
    for (int i = 1; i < (int)factorial.size(); ++i) {
        factorial[i] = factorial[i-1] * i;
    }

    mint ans = 0;
    for (int i = 1; i <= m; ++i) {
        mint numPerm = 1;
        for (const auto &[_, c] : factorized[i]) {
            numPerm *= factorial[c + n-1] / (factorial[c] * factorial[n-1]);
        }
        ans += numPerm;
    }

    cout << ans.val() << endl;

    return 0;
}