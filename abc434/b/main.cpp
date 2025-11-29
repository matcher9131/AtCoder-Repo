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
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
    }

    vector<ll> s(m), c(m);
    for (ll i = 0; i < n; ++i) {
        ++c[a[i]];
        s[a[i]] += b[i];
    }

    cout << fixed << setprecision(15);
    for (ll i = 0; i < m; ++i) {
        cout << (double)s[i] / c[i] << endl;
    }

    return 0;
}