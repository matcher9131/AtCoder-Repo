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

    unordered_map<ll, unordered_map<ll, ll>> vec;
    unordered_map<ll, unordered_map<ll, ll>> midpoint;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            ll dx = x[j] - x[i], dy = y[j] - y[i];
            if (dx == 0) {
                ++vec[0][1];
            } else if (dy == 0) {
                ++vec[1][0];
            } else {
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                ll g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                ++vec[dx][dy];
            }

            ++midpoint[x[i]+x[j]][y[i]+y[j]];
        }
    }

    ll ans = 0;
    for (const auto &[_, inner] : vec) {
        for (const auto &[__, c] : inner) {
            ans += c * (c - 1) / 2;
        }
    }
    for (const auto &[_, inner] : midpoint) {
        for (const auto &[__, c] : inner) {
            ans -= c * (c - 1) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}

// 3708ms
