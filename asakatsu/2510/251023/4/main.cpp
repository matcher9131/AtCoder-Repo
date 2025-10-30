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
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
    }
    sort(b.begin(), b.end());
    vector<ll> sb(m+1);
    for (ll j = 0; j < m; ++j) {
        sb[j+1] = sb[j] + b[j];
    }

    ll ans = 0;
    for (const ll ai : a) {
        ll k = lower_bound(b.begin(), b.end(), p-ai) - b.begin();
        ans += ai * k + sb[k] + (m-k) * p;
    }
    cout << ans << endl;

    return 0;
}