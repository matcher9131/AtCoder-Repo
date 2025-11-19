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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> b{ 0, 360 };
    for (ll i = 0; i < n; ++i) {
        b.push_back((b.back() + a[i]) % 360);
    }
    sort(b.begin(), b.end());
    ll ans = 0;
    for (ll i = 1; i < (ll)b.size(); ++i) {
        chmax(ans, b[i] - b[i-1]);
    }
    cout << ans << endl;

    return 0;
}