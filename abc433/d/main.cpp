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
    vector<unordered_map<ll, ll>> dict(11);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        ll numDigits = to_string(a[i]).size();
        ++dict[numDigits][a[i] % m];
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll r = a[i] % m;
        for (ll j = 1; j <= 10; ++j) {
            r *= 10;
            r %= m;
            ans += dict[j][r == 0 ? 0 : m-r];
        }
    }
    cout << ans << endl;

    return 0;
}