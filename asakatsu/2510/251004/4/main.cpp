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
    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    for (ll i = 0; i < m; ++i) {
        que.emplace(a[i]-b[i], a[i]);
    }

    ll ans = 0;
    while (!que.empty()) {
        auto [diff, need] = que.top();
        que.pop();
        if (n < need) continue;
        ll c = (n - (need-1) + (diff-1)) / diff;
        ans += c;
        n -= c * diff;
    }
    cout << ans << endl;

    return 0;
}