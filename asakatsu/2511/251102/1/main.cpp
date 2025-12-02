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
    vector<vector<ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        ll li;
        cin >> li;
        a[i].resize(li);
        for (ll j = 0; j < li; ++j) {
            cin >> a[i][j];
        }
    }

    while (nq--) {
        ll si, ti;
        cin >> si >> ti;
        --si;
        --ti;
        cout << a[si][ti] << endl;
    }

    return 0;
}