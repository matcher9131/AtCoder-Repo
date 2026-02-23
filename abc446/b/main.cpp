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
    vector<vector<ll>> x(n);
    for (ll i = 0; i < n; ++i) {
        ll li;
        cin >> li;
        for (ll j = 0; j < li; ++j) {
            ll xij;
            cin >> xij;
            --xij;
            x[i].push_back(xij);
        }
    }

    vector<bool> done(m);
    for (ll i = 0; i < n; ++i) {
        ll ans = -1;
        for (const ll xij : x[i]) {
            if (!done[xij]) {
                ans = xij;
                done[xij] = true;
                break;
            }
        }
        cout << ans+1 << endl;
    }

    return 0;
}