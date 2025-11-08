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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    vector<ll> b(m);
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
    }
    sort(b.begin(), b.end());

    ll j = 0;
    for (ll i = 0; i < n; ++i) {
        while (j < m && b[j] < h[i]) ++j;
        if (j == m) break;
        --k;
        ++j;
    }

    cout << (k<=0 ? "Yes" : "No") << endl;

    return 0;
}