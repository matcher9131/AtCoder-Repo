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
    vector<ll> c(9);
    for (ll i = 0; i < 9; ++i) {
        cin >> c[i];
    }
    reverse(c.begin(), c.end());

    vector<vector<ll>> memo(n+1);
    memo[0] = vector<ll>(9);
    auto dfs = [&](auto f, ll x) -> vector<ll> {
        if (!memo[x].empty()) return memo[x];
        vector<ll> res(9);
        for (ll i = 0; i < 9; ++i) {
            if (x < c[i]) continue;
            vector<ll> v = f(f, x - c[i]);
            ++v[i];
            ll sumRes = accumulate(res.begin(), res.end(), 0LL);
            ll sumV = accumulate(v.begin(), v.end(), 0LL);
            if (sumRes < sumV || (sumRes == sumV && res < v)) res = v;
        }
        return memo[x] = res;
    };

    vector<ll> v = dfs(dfs, n);
    string ans;
    for (ll i = 0; i < 9; ++i) {
        for (ll j = 0; j < v[i]; ++j) {
            ans += '9' - i;
        }
    }
    cout << (ans.empty() ? "0" : ans) << endl;

    return 0;
}