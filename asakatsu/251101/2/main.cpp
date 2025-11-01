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
    vector<ll> r(n);
    for (ll i = 0; i < n; ++i) {
        cin >> r[i];
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<ll> prior(n);
    for (ll i = 0; i < n/2; ++i) {
        prior[i] = 2*i + 1;
        prior[n-1-i] = 2*i;
    }
    if (n%2) prior[n/2] = n-1;
    for (ll i = 0; i < n; ++i) {
        r[i] = prior[r[i]-1];
        c[i] = prior[c[i]-1];
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll i, j;
        cin >> i >> j;
        --i;
        --j;
        ll k = min(r[i], c[j]);
        cout << (k%2 ? '.' : '#');
    }
    cout << endl;

    return 0;
}