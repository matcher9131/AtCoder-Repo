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
    cin >> n;

    vector<mint> fact(n);
    fact[0] = 1;
    for (int i = 1; i < n; ++i) {
        fact[i] = fact[i-1] * i;
    }

    mint p = (mint)1 / 2;
    vector<mint> f(n+1);
    // f_0 = (1\2)x・(1-x)^(N-1)
    for (int i = 0; i < n; ++i) {
        f[i+1] = p * fact[n-1] / (fact[i] * fact[n-1-i]) * (i % 2 ? -1 : 1);
    }
    // c_j = ∑_{k=0} 2^(-kj) = 1/(1 - 2^(-j))
    vector<mint> c(n+1);
    c[0] = 1;
    for (int i = 1; i <= n; ++i) {
        c[i] = (1 - p.pow(i)).inv();
    }

    vector<mint> ans(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            ans[i] += f[j] * c[j];
        }

        // f_iからf_{i+1}を作成
        // 1-xで割る（代わりに累積和を取る）
        for (int j = 0; j < n; ++j) {
            f[j+1] += f[j];
        }
        // 1-x/2を掛ける
        for (int j = n; j >= 1; --j) {
            f[j] -= p * f[j-1];
        }
    }

    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i].val() << " \n"[i == (int)ans.size() - 1];
    }
    
    return 0;
}