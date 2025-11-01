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
    vector<ll> x(n+1);
    x[0] = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> x[i+1];
    }

    set<pair<ll, ll>> p;
    vector<ll> ans(n+1);
    p.emplace(x[0], 0);
    p.emplace(x[1], 1);
    ans[0] = x[1];
    ans[1] = x[1];
    ll ansSum = 2*x[1];
    cout << ansSum << "\n";

    auto update = [&](set<pair<ll, ll>>::iterator &it) -> void {
        if (it != p.begin()) {
            auto itl = it;
            --itl;
            ll dl = it->first - itl->first;
            auto itr = it;
            ++itr;
            ll dr = itr != p.end() ? itr->first - it->first : INF;
            ll d = min(dl, dr);
            if (d < ans[it->second]) {
                ansSum += d - ans[it->second];
                ans[it->second] = d;
            }
        } else {
            auto itr = it;
            ++itr;
            ll d = itr->first - it->first;
            if (d < ans[it->second]) {
                ansSum += d - ans[it->second];
                ans[it->second] = d;
            }
        }
    };

    for (ll i = 2; i < n+1; ++i) {
        auto [it, _] = p.emplace(x[i], i);
        auto itl = it;
        --itl;
        auto itr = it;
        ++itr;
        update(itl);
        if (itr != p.end()) update(itr);
        ll dl = x[i] - itl->first;
        ll dr = itr != p.end() ? itr->first - x[i] : INF;
        ansSum += min(dl, dr);
        ans[it->second] = min(dl, dr);
        cout << ansSum << "\n";
    }

    return 0;
}