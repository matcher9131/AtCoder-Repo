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
    ll n, nq;
    cin >> n >> nq;
    vector<pair<ll, ll>> q(nq);
    vector<ll> a;
    for (ll qi = 0; qi < nq; ++qi) {
        ll l, r;
        cin >> l >> r;
        --l;
        q[qi] = {l, r};
        a.push_back(l);
        a.push_back(r);
    }
    a.push_back(INF);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (ll qi = 0; qi < nq; ++qi) {
        q[qi].first = lower_bound(a.begin(), a.end(), q[qi].first) - a.begin();
        q[qi].second = lower_bound(a.begin(), a.end(), q[qi].second) - a.begin();
    }

    set<ll> white;
    for (ll i = 0; i < (ll)a.size(); ++i) {
        white.insert(i);
    }

    ll ans = n;
    for (const auto &[l, r] : q) {
        auto itl = white.lower_bound(l);
        auto itr = white.lower_bound(r);
        for (auto it = itl; it != itr; ++it) {
            ans -= a[*it + 1] - a[*it];
        }
        white.erase(itl, itr);
        cout << ans << "\n";
    }

    return 0;
}