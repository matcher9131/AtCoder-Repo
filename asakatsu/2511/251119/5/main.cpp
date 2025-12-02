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
    vector<pair<ll, ll>> s;
    for (ll i = 0; i < n; ++i) {
        ll t, d;
        cin >> t >> d;
        s.emplace_back(t, t+d);
    }
    sort(s.begin(), s.end());

    ll ans = 0;
    auto it = s.begin();
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll t = 0;
    while (true) {
        if (que.empty()) {
            if (it == s.end()) break;
            t = it->first;
        }
        while (it != s.end() && it->first == t) {
            que.push(it->second);
            ++it;
        }

        while (!que.empty() && que.top() < t) que.pop();
        if (!que.empty()) {
            ++ans;
            que.pop();
        }
        ++t;
    }

    cout << ans << endl;

    return 0;
}