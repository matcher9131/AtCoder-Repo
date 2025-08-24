#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll x, y;
    cin >> x >> y;

    ll ans = (x+y) % 12;
    if (ans == 0) ans = 12;
    cout << ans << endl;

    return 0;
}