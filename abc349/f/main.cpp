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
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        if (m % ai == 0) a.push_back(ai);
    }
    n = a.size();

    if (m == 1) {
        cout << (((mint)2).pow(a.size()) - 1).val() << endl;
        return 0;
    }

    vector<ll> factor;
    ll mm = m;
    for (ll p = 2; p * p <= m; ++p) {
        if (mm % p != 0) continue;
        ll pi = 1;
        while (mm % p == 0) {
            mm /= p;
            pi *= p;
        }
        factor.push_back(pi);
    }
    if (mm > 1) {
        factor.push_back(mm);
    }
    int fn = factor.size();

    vector<int> patternCount(1 << fn);
    for (int i = 0; i < n; ++i) {
        int pattern = 0;
        for (int fi = 0; fi < fn; ++fi) {
            if (a[i] % factor[fi] == 0) pattern |= 1LL << fi;
        }
        ++patternCount[pattern];
    }

    // dp[i]: patternのbitwise orがiになるようなものの個数
    vector<mint> dp(1 << fn);
    dp[0] = 1;
    for (int i = 0; i < 1 << fn; ++i) {
        vector<mint> ndp(1 << fn);
        for (int j = 0; j < 1 << fn; ++j) {
            // iを含める
            ndp[i|j] += dp[j] * (((mint)2).pow(patternCount[i]) - 1);
            // iを含めない
            ndp[j] += dp[j];
        }
        dp = ndp;
    }

    cout << dp[(1 << fn) - 1].val() << endl;

    return 0;
}