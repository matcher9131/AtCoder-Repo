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
    int n, m, k;
    cin >> n >> m >> k;

    vector<mint> base(n);
    base[0] = m;
    for (int i = 1; i < n; ++i) {
        base[i] = (m - 1) * base[i-1];
    }

    vector<mint> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = i * fact[i-1];
    }

    mint ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += base[n-1-i] * fact[n-1] / (fact[i] * fact[n-1-i]);
    }

    cout << ans.val() << endl;

    return 0;
}