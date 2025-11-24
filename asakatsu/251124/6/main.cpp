#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
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
    vector<vector<ll>> g(n);
    for (ll i = 1; i < n; ++i) {
        ll pi;
        cin >> pi;
        --pi;
        g[pi].push_back(i);
    }

    vector<ll> pre(n), post(n), depth(n);
    auto dfs = [&](auto dfs, ll from, ll d, ll &t) -> void {
        pre[from] = t++;
        depth[from] = d;
        for (const ll to : g[from]) {
            dfs(dfs, to, d+1, t);
        }
        post[from] = t++;
    };
    ll t = 0;
    dfs(dfs, 0, 0, t);

    vector<ll> td(2*n+1, n);
    for (ll i = 0; i < n; ++i) {
        td[post[i]] = depth[i];
    }

    ll nq;
    cin >> nq;
    vector<tuple<ll, ll, ll, ll>> q(nq);
    for (ll qi = 0; qi < nq; ++qi) {
        ll ui, di;
        cin >> ui >> di;
        --ui;
        q[qi] = { pre[ui], post[ui]+1, di, qi };
    }
    ll m = sqrt(2*n);
    auto comparer = [&](tuple<ll, ll, ll, ll> &x, tuple<ll, ll, ll, ll> &y) {
        auto [xl, xr, _0, _1] = x;
        auto [yl, yr, _2, _3] = y;
        if (xl / m < yl / m) return true;
        if (xl / m == yl / m && xr < yr) return true;
        return false;
    };
    sort(q.begin(), q.end(), comparer);

    vector<ll> ans(nq);
    vector<ll> cd(n+1);
    ll l = 0, r = 0;
    for (const auto &[li, ri, di, qi] : q) {
        while (l > li) ++cd[td[--l]];
        while (r < ri) ++cd[td[r++]];
        while (l < li) --cd[td[l++]];
        while (r > ri) --cd[td[--r]];
        ans[qi] = cd[di];
    }

    for (ll qi = 0; qi < nq; ++qi) {
        cout << ans[qi] << endl;
    }

    return 0;
}