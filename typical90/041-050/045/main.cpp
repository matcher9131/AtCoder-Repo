#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 2e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

inline ll d(ll x1, ll y1, ll x2, ll y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<ull> groups(k);
    ll ans = INF;
    groups[0] = 1ULL << 0;
    
    auto dfs = [&](auto f, ll i, ll numGroups) -> void {
        if (i == n) {
            ll res = 0;
            for (const auto &group : groups) {
                for (ll j = 0; j < n; ++j) {
                    if ((group & (1ULL << j)) == 0) continue;
                    for (ll k = j+1; k < n; ++k) {
                        if ((group & (1ULL << k)) == 0) continue;
                        chmax(res, d(x[j], y[j], x[k], y[k]));
                    }
                }
            }
            chmin(ans, res);
        } else {
            if (k - numGroups < n - i) {
                for (ll gi = 0; gi < numGroups; ++gi) {
                    groups[gi] |= 1ULL << i;
                    f(f, i+1, numGroups);
                    groups[gi] ^= 1ULL << i;
                }
            }
            if (numGroups < k) {
                groups[numGroups] |= 1ULL << i;
                f(f, i+1, numGroups+1);
                groups[numGroups] ^= 1ULL << i;
            }
        }
    };
    dfs(dfs, 1, 1);

    cout << ans << endl;
    return 0;
}