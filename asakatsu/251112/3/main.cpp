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

    vector<ll> left(n), right(n);
    stack<pair<ll, ll>> stl, str;
    stl.emplace(0, -1);
    for (ll i = 0; i < n; ++i) {
        while (stl.top().first >= a[i]) stl.pop();
        left[i] = stl.top().second + 1;
        stl.emplace(a[i], i);
    }
    str.emplace(0, n);
    for (ll i = n - 1; i >= 0; --i) {
        while (str.top().first >= a[i]) str.pop();
        right[i] = str.top().second - 1;
        str.emplace(a[i], i);
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        chmax(ans, a[i] * (right[i] - left[i] + 1));
    }
    cout << ans << endl;

    return 0;
}