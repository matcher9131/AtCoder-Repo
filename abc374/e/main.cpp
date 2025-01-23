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

constexpr ll W_INF = 1e10;
constexpr ll X_INF = 1e18;

ll divCeil(ll x, ll y) {
    return (x + y - 1) / y;
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // 工程iでwi個の製品を処理するのに予算xi円以内になるかどうか
    auto canAfford = [&](int i, ll wi, ll xi) -> bool {
        for (ll s = 0; s <= b[i]; ++s) {
            ll t = divCeil(max(0LL, wi - s * a[i]), b[i]);
            if (s * p[i] + t * q[i] <= xi) return true;
        }
        for (ll t = 0; t <= a[i]; ++t) {
            ll s = divCeil(max(0LL, wi - t * b[i]), a[i]);
            if (s * p[i] + t * q[i] <= xi) return true;
        }
        return false;
    };

    auto searchX = [&](int i, ll wi) -> ll {
        ll ng = 0;
        ll ok = X_INF;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (canAfford(i, wi, mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    auto withinX = [&](ll wi) -> bool {
        ll xSum = 0;
        for (int i = 0; i < n; ++i) {
            xSum += searchX(i, wi);
            if (xSum > x) {
                return false;
            }
        }
        return true;
    };
    
    ll ng = W_INF;
    ll ok = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (withinX(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}