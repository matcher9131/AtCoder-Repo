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

mint powMInt(int x, int y) {
    mint ans = 1;
    for (int i = 0; i < y; ++i) {
        ans *= x;
    }
    return ans;
}

int main() {
    ll l, r;
    cin >> l >> r;

    // 10^k <= x < 10^(k+1)となるk
    auto base10 = [](ll x) -> int {
        int ans = 0;
        for (; x > 0; ++ans) {
            x /= 10;
        }
        return ans - 1;
    };

    // l <= x <= rを満たす数をx回書いたときの桁数の合計
    // ただし10^k <= l <= r < 10^(k+1)を満たすこと
    auto ndk = [](mint l, mint r, int k) -> mint {
        // 10^k <= x < 10^(k+1)はk+1桁
        return (l + r) * (r - l + 1) / 2 * (k + 1);
    };

    // [1, R]を題意の通りに書いたときの桁数の合計
    auto nd = [&](ll x) -> mint {
        if (x == 0) return 0;
        mint ans = 0;
        int k = base10(x);
        for (int i = 0; i < k; ++i) {
            ans += ndk(powMInt(10, i), powMInt(10, i + 1) - 1, i);
        }
        ans += ndk(powMInt(10, k), x, k);
        return ans;
    };
    
    mint ans = nd(r) - nd(l - 1);

    cout << ans.val() << endl;

    return 0;
}