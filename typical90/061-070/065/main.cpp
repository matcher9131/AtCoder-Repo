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
#include <atcoder/convolution>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
    int a, b, c, k, x, y, z;
    cin >> a >> b >> c >> k >> x >> y >> z;

    int aMin = k - y, bMin = k - z, cMin = k - x;

    vector<mint> fact(max({a, b, c}) + 1);
    fact[0] = 1;
    for (int i = 1; i < (int)fact.size(); ++i) {
        fact[i] = i * fact[i-1];
    }

    vector<mint> ca(a + 1), cb(b + 1), cc(c + 1);
    for (int ai = 0; ai <= a; ++ai) {
        ca[ai] = ai < aMin ? 0 : fact[a] / (fact[ai] * fact[a - ai]);
    }
    for (int bi = 0; bi <= b; ++bi) {
        cb[bi] = bi < bMin ? 0 : fact[b] / (fact[bi] * fact[b - bi]);
    }
    for (int ci = 0; ci <= c; ++ci) {
        cc[ci] = ci < cMin ? 0 : fact[c] / (fact[ci] * fact[c - ci]);
    }
    vector<mint> conv = atcoder::convolution(ca, cb);
    
    mint ans = 0;
    for (int xi = 0; xi <= x; ++xi) {
        int ci = k - xi;
        if (ci > c) continue;
        ans += conv[xi] * cc[ci];
    }

    cout << ans.val() << endl;
    return 0;
}