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
    string s;
    cin >> s;

    unordered_map<ll, pair<ll, ll>> m;
    for (ll i = 0; i < n; ++i) {
        if (!m.contains(y[i])) m[y[i]] = {-INF, INF};
        if (s[i] == 'L') {
            chmax(m[y[i]].first, x[i]);
        } else {
            chmin(m[y[i]].second, x[i]);
        }
    }

    for (const auto &[_, p] : m) {
        auto [l, r] = p;
        if (l > r) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}