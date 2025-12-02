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
    vector<bitset<3000>> g(n);
    for (ll i = 0; i < n; ++i) {
        string si;
        cin >> si;
        reverse(si.begin(), si.end());
        g[i] = bitset<3000>(si);
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            if (g[i][j]) {
                ans += (g[i] & g[j]).count();
            }
        }
    }
    cout << ans/3 << endl;

    return 0;
}