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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int n = a + b + c + d;
    vector<mint> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i-1] * i;
    }

    mint ans = 0;
    for (int i = 0; i <= c; ++i) {
        // 一番左のブドウが先頭からa+i番目に来る並べ方 (c-i+d-1)C(d-1)
        mint p1 = fact[c-i + d-1] / (fact[c-i] * fact[d-1]);
        // オレンジの入れ方 (b+a+i)C(b)
        mint p2 = fact[b+a+i] / (fact[b] * fact[a+i]);
        ans += p1 * p2;
    }

    cout << ans.val() << endl;
    return 0;
}