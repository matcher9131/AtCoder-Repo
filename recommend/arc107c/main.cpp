#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    atcoder::dsu gr(n), gc(n);
    for (ll x = 0; x < n; ++x) {
        for (ll y = x+1; y < n; ++y) {
            bool ok = true;
            for (ll i = 0; i < n; ++i) {
                if (a[i][x] + a[i][y] > k) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                gc.merge(x, y);
            }
        }
    }
    for (ll x = 0; x < n; ++x) {
        for (ll y = x+1; y < n; ++y) {
            bool ok = true;
            for (ll i = 0; i < n; ++i) {
                if (a[x][i] + a[y][i] > k) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                gr.merge(x, y);
            }
        }
    }

    vector<mint> fact(n+1);
    fact[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        fact[i] = fact[i-1] * i;
    }

    mint ans = 1;
    for (const auto &v : gc.groups()) {
        ans *= fact[v.size()];
    }
    for (const auto &v : gr.groups()) {
        ans *= fact[v.size()];
    }

    cout << ans.val() << endl;
    return 0;
}