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
using namespace std;
using ll = long long;

pair<bool, ll> product(ll x, ll y) {
    if (y == 0) return make_pair(false, 0);
    if (x <= LLONG_MAX / y) return make_pair(false, x * y);
    return make_pair(true, 0);
}
pair<bool, ll> product(pair<bool, ll> x, ll y) {
    if (x.first) return make_pair(true, 0);
    return product(x.second, y);
}

int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    ll ng = m + 1;
    pair<ll, ll> ok(0, 0);

    // x円以下をすべて買い、x+1円を0個以上買う買い方ができれば買った個数を返す
    // 無理なら-1を返す
    auto buyAll = [&](ll x) -> ll {
        ll sum = 0;
        vector<ll> count(n);
        for (int i = 0; i < n; ++i) {
            // k個目(1-indexed)の値段 = (2*k - 1) * p[i]
            ll k = (x / p[i] + 1LL) / 2LL;
            auto [overflows, ps] = product(product(k, k), p[i]);
            if (overflows || m - sum < ps) return -1LL;
            sum += ps;
            count[i] = k;
        }
        for (int i = 0; i < n; ++i) {
            if (m - sum < x + 1) break;
            if ((2 * count[i] + 1) * p[i] == x + 1) {
                sum += x + 1;
                ++count[i];
            }
        }
        return accumulate(count.begin(), count.end(), 0LL);
    };

    while (abs(ok.first - ng) > 1) {
        ll mid = (ok.first + ng) / 2LL;
        ll count = buyAll(mid);
        if (count > -1) ok = make_pair(mid, count);
        else ng = mid;
    }

    cout << ok.second << endl;

    return 0;
}