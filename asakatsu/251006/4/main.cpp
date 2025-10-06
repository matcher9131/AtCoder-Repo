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
    set<ll> a;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a.insert(ai);
    }

    ll ans = 0;
    while (!a.empty()) {
        for (ll x = *a.begin(); x <= 1e9; x *= 2) {
            a.erase(x);
        }
        ++ans;
    }
    cout << ans << endl;

    return 0;
}