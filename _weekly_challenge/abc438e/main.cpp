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
    ll n, nq;
    cin >> n >> nq;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<vector<ll>> person(30, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        person[0][i] = a[i];
    }
    for (ll bit = 1; bit < 30; ++bit) {
        for (ll i = 0; i < n; ++i) {
            person[bit][i] = person[bit-1][person[bit-1][i]];
        }
    }

    vector<vector<ll>> water(30, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        water[0][i] = i+1;
    }
    for (ll bit = 1; bit < 30; ++bit) {
        for (ll i = 0; i < n; ++i) {
            water[bit][i] = water[bit-1][i] + water[bit-1][person[bit-1][i]];
        }
    }

    while (nq--) {
        ll t, b;
        cin >> t >> b;
        --b;

        ll ans = 0;
        for (ll bit = 0; bit < 30; ++bit) {
            if (t & (1LL << bit)) {
                ans += water[bit][b];
                b = person[bit][b];
            }
        }
        cout << ans << endl;
    }

    return 0;
}