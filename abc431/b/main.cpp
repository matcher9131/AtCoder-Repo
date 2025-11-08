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
    ll x, n;
    cin >> x >> n;
    vector<ll> w(n);
    for (ll i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<bool> s(n);
    ll nq;
    cin >> nq;
    while (nq--) {
        ll pi;
        cin >> pi;
        --pi;
        x += s[pi] ? -w[pi] : w[pi];
        cout << x << endl;
        s[pi] = !s[pi];
    }

    return 0;
}