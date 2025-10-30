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
    string s, t;
    cin >> s >> t;

    ll ans = 3;
    if (t.starts_with(s)) ans -= 2;
    if (t.ends_with(s)) ans -= 1;
    cout << ans << endl;

    return 0;
}