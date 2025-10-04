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
    // [prime, [exp, index][]][]
    unordered_map<ll, set<pair<ll, ll>, greater<>>> primeMap;
    for (ll i = 0; i < n; ++i) {
        ll m;
        cin >> m;
        for (ll j = 0; j < m; ++j) {
            ll p, e;
            cin >> p >> e;
            primeMap[p].emplace(e, i);
        }
    }

    unordered_set<ll> ans;
    for (const auto &[_, s] : primeMap) {
        if ((ll)s.size() == 1) ans.insert(s.begin()->second);
        else if ((ll)s.size() > 1) {
            auto it = s.begin();
            ll em1 = it->first;
            ++it;
            ll em2 = it->first;
            if (em1 > em2) ans.insert(s.begin()->second);
        }
    }
    cout << ((ll)ans.size() == n ? n : (ll)ans.size() + 1) << endl;

    return 0;
}