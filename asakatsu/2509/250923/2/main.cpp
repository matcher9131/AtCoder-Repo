#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ll x = i;
        ll sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        if (a <= sum && sum <= b) ans += i;
    }

    cout << ans << endl;

    return 0;
}