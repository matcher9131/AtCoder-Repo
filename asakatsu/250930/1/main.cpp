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
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector<ll> q(n), revQ(n);
    for (ll i = 0; i < n; ++i) {
        cin >> q[i];
        --q[i];
        revQ[q[i]] = i;
    }

    for (ll i = 0; i < n; ++i) {
        cout << q[p[revQ[i]]] + 1 << " \n"[i == n - 1];
    }

    return 0;
}