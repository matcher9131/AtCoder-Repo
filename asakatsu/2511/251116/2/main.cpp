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

    ll ans = 0;
    ll sum = 0;
    ll sumSq = 0;
    for (ll i = 0; i < n; ++i) {
        ans += i * a[i] * a[i];
        ans -= 2 * a[i] * sum;
        ans += sumSq;
        sum += a[i];
        sumSq += a[i] * a[i];
    }
    cout << ans << endl;

    return 0;
}