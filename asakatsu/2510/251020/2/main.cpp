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
    ll n, k;
    cin >> n >> k;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    for (ll i = 0; i < n; ++i) {
        ll ai, bi;
        cin >> ai >> bi;
        que.emplace(ai, bi);
    }

    ll ans = k;
    while (!que.empty()) {
        auto [i, v] = que.top();
        if (i > ans) break;
        que.pop();
        ans += v;
    }
    cout << ans << endl;

    return 0;
}