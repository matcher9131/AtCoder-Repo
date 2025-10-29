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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
    }

    for (ll j = 0; j < m; ++j) {
        auto it = find(a.begin(), a.end(), b[j]);
        if (it != a.end()) a.erase(it);
    }

    for (ll i = 0; i < (ll)a.size(); ++i) {
        cout << a[i] << " \n"[i == (ll)a.size() - 1];
    }

    return 0;
}