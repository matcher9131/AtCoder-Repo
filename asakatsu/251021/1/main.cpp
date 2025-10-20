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
    ll h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;

    ll ans = 60*h2 + m2 - 60*h1 - m1 - k;
    cout << (ans > 0 ? ans : 0) << endl;

    return 0;
}