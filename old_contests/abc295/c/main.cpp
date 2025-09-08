#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        ++m[ai];
    }

    ll ans = 0;
    for (const auto &[_, count] : m) {
        ans += count / 2;
    }

    cout << ans << endl;
    return 0;
}