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
    ll h, w;
    cin >> h >> w;
    ll i, j;
    cin >> i >> j;
    --i;
    --j;

    ll ans = 4;
    if (i == 0) --ans;
    if (i == h-1) --ans;
    if (j == 0) --ans;
    if (j == w-1) --ans;
    cout << ans << endl;

    return 0;
}