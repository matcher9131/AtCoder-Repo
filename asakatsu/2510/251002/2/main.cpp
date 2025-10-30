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
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> t(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> t[i][j];
        }
    }

    vector<ll> p(n-1);
    for (ll i = 0; i < n-1; ++i) {
        p[i] = i+1;
    }

    ll ans = 0;
    do {
        ll sum = 0;
        ll prev = 0;
        for (const ll v : p) {
            sum += t[prev][v];
            prev = v;
        }
        sum += t[prev][0];
        if (sum == k) ++ans;
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;

    return 0;
}