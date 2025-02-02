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
using mint = atcoder::modint1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> primes;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int p = 2; p * p <= a[i]; ++p) {
            int k = 0;
            while (x % p == 0) {
                x /= p;
                ++k;
            }
            primes[p] = max(primes[p], k);
        }
        primes[x] = max(primes[x], 1);
    }

    mint lcm = accumulate(primes.begin(), primes.end(), (mint)1, [](mint x, unordered_map<int, int>::value_type kvp) {
        return x * ((mint)kvp.first).pow(kvp.second);
    });

    mint ans = accumulate(a.begin(), a.end(), (mint)0, [&](mint x, int ai) {
        return x + lcm / ai;
    });

    cout << ans.val() << endl;

    return 0;
}