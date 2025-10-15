#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<pair<ll, ll>> vec;
    vector<pair<ll, ll>> midpoint;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            ll dx = x[j] - x[i], dy = y[j] - y[i];
            if (dx == 0) {
                vec.emplace_back(0, 1);
            } else if (dy == 0) {
                vec.emplace_back(1, 0);
            } else {
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                ll g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                vec.emplace_back(dx, dy);
            }

            midpoint.emplace_back(x[i]+x[j], y[i]+y[j]);
        }
    }
    sort(vec.begin(), vec.end());
    sort(midpoint.begin(), midpoint.end());

    auto count = [&](vector<pair<ll, ll>> &v) {
        ll m = v.size();
        ll res = 0;
        ll left = 0;
        while (left < m) {
            ll right = left;
            while (right < m && v[right] == v[left]) ++right;
            res += (right - left) * (right - left - 1) / 2;
            left = right;
        }
        return res;
    };

    cout << count(vec) - count(midpoint) << endl;
    return 0;
}

// 614ms
