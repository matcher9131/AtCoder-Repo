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


int main() {
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    auto f = [&](const vector<ll> &x) -> pair<ll, ll> {
        ll x0 = x[0] - (d == 0 ? 1 : d);
        ll sx = accumulate(x.begin(), x.end(), 0LL, [&](ll acc, ll value) { return acc + abs(value - x0); });
        return { x0, sx };
    };
    auto [x0, sx] = f(x);
    auto [y0, sy] = f(y);

    auto g = [&](vector<ll> &dst, const vector<ll> &x, ll base, ll sum) -> void {
        dst.push_back(sum);
        ll xx = base;
        int nl = 0;
        auto it = x.begin();
        while (true) {
            ++xx;
            sum += 2 * nl - n;
            if (sum > d && sum > dst.back()) break;
            dst.push_back(sum);
            auto itr = it;
            for (; itr != x.end() && *itr == xx; ++itr);
            nl += itr - it;
            it = itr;
        }
    };
    // x'=x-x0としてdist[x']を管理
    vector<ll> xd;
    vector<ll> yd;
    g(xd, x, x0, sx);
    g(yd, y, y0, sy);

    auto itYdMin = min_element(yd.begin(), yd.end());
    auto itYdMinR = reverse_iterator{itYdMin};

    ll ans = 0;
    for (const ll cxd : xd) {
        ll cyd = d - cxd;
        if (cyd < *itYdMin) continue;
        auto itr = upper_bound(itYdMin, yd.end(), cyd);
        auto itl = upper_bound(itYdMinR, yd.rend(), cyd);
        ans += (itr - itYdMin) + (itl - itYdMinR);
    }

    cout << ans << endl;

    return 0;
}