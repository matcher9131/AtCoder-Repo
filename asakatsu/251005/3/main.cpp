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
    string s;
    cin >> s;
    ll nc = 0, na = 0;
    for (ll i = 0; i < n; ++i) {
        ++(s[i] == '0' ? nc : na);
    }
    vector<ll> w(n);
    for (ll i = 0; i < n; ++i) {
        cin >> w[i];
    }

    map<ll, pair<ll, ll>> m;
    for (ll i = 0; i < n; ++i) {
        ++(s[i] == '0' ? m[w[i]].first : m[w[i]].second);
    }
    m[INF] = {0, 0};
    ll cc = 0, ca = 0;
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        it->second.first += cc;
        it->second.second += ca;
        cc = it->second.first;
        ca = it->second.second;
    }

    ll ans = 0;
    for (const auto &[wi, p] : m) {
        auto [wrongChild, correctAdult] = p;
        ll correctChild = nc - wrongChild;
        chmax(ans, correctChild + correctAdult);
    }
    cout << ans << endl;

    return 0;
}