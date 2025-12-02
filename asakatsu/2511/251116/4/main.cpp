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
    sort(a.begin(), a.end());

    mint ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += a[i] * a[i];
    }
    mint powSum = 0;
    for (ll i = 0; i < n; ++i) {
        if (i > 0) ans += mint(2).pow(i-1) * a[i] * powSum;
        powSum += mint(2).pow(i).inv() * a[i];
    }
    cout << ans.val() << endl;

    return 0;
}