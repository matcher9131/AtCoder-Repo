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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> co(30);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 30; ++j) {
            if (a[i] & (1LL << j)) ++co[j];
        }
    }

    ll ans = accumulate(a.begin(), a.end(), 0LL);
    for (ll i = 0; i < n; ++i) {
        ll cur = 0;
        for (ll j = 0; j < 30; ++j) {
            cur += ((a[i] & (1LL << j)) ? (n-co[j]) : co[j]) * (1LL << j);
        }
        chmax(ans, cur);
    }
    cout << ans << endl;

    return 0;
}