#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll x, y;
    cin >> x >> y;

    ll ans = 1;
    while (x <= y) {
        if (2*x > y) break;
        x *= 2;
        ++ans;
    }

    cout << ans << endl;

    return 0;
}