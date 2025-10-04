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
    vector<ll> t(n);
    for (ll i = 0; i < n; ++i) {
        cin >> t[i];
    }
    ll m;
    cin >> m;
    vector<ll> p(m), x(m);
    for (ll i = 0; i < m; ++i) {
        cin >> p[i] >> x[i];
        --p[i];
    }

    ll sum = accumulate(t.begin(), t.end(), 0LL);
    for (ll i = 0; i < m; ++i) {
        cout << sum - t[p[i]] + x[i] << endl;
    }

    return 0;
}