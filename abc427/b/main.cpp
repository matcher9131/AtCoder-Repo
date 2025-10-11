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

    auto f = [&](ll x) -> ll {
        ll res = 0;
        while (x > 0) {
            res += x%10;
            x /= 10;
        }
        return res;
    };

    vector<ll> ans(n+1);
    ans[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j < i; ++j) {
            ans[i] += f(ans[j]);
        }
    }
    cout << ans[n] << endl;

    return 0;
}