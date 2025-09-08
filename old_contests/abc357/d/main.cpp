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
using ull = unsigned long long;
using mint = atcoder::modint998244353;

int main() {
    ull n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int ln = bit_width(n);

    ull _n = n;
    int w = 0;
    for (; _n > 0; ++w) {
        _n /= 10;
    }

    mint m10 = 10;

    // db[i] = Σ(10^w)^(2^i)
    vector<mint> db(ln);
    db[0] = 1;
    for (int i = 1; i < ln; ++i) {
        db[i] = m10.pow(w).pow(1LL << (i - 1)) * db[i-1] + db[i-1];
    }

    mint ans = 0;
    mint base = 1;
    for (int bit = 0; bit < ln; ++bit) {
        if (n & (1ULL << bit)) {
            ans += db[bit] * base;
            base *= m10.pow(w).pow(1LL << bit);
        }
    }
    ans *= n;

    cout << ans.val() << endl;
    return 0;
}