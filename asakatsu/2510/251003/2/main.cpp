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
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<vector<ll>> a(n-1, vector<ll>(n-1));
    for (ll i = 0; i < n-1; ++i) {
        for (ll j = 0; j < n-1; ++j) {
            if (s[i][j] == '.' && s[i+1][j] == '.' && s[i][j+1] == '.' && s[i+1][j+1] == '.') a[i][j] = 1;
        }
    }

    vector<vector<ll>> sum(n, vector<ll>(n));
    for (ll i = 0; i < n-1; ++i) {
        for (ll j = 0; j < n-1; ++j) {
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + a[i][j];
        }
    }

    while (nq--) {
        ll u, d, l, r;
        cin >> u >> d >> l >> r;
        --u;
        --d;
        --l;
        --r;
        cout << sum[d][r] - sum[u][r] - sum[d][l] + sum[u][l] << endl;
    }

    return 0;
}