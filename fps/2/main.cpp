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
    vector<ll> a(n+1);
    for (ll i = 0; i < n+1; ++i) {
        cin >> a[i];
    }
    vector<ll> c(n+m+1);
    for (ll i = 0; i < n+m+1; ++i) {
        cin >> c[i];
    }

    vector<ll> b(m+1);
    for (ll j = m; j >= 0; --j) {
        b[j] = c[j+n] / a[n];
        for (ll i = n; i >= 0; --i) {
            c[i+j] -= b[j] * a[i];
        }
    }
    
    for (ll i = 0; i < (ll)b.size(); ++i) {
        cout << b[i] << " \n"[i == (ll)b.size() - 1];
    }

    return 0;
}