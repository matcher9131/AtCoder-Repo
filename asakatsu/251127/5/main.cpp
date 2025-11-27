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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());

    auto calc = [&](ll x, ll y, ll z) -> ll {
        return a[x]*b[y] + b[y]*c[z] + c[z]*a[x];
    };

    priority_queue<tuple<ll, ll, ll, ll>> que;
    set<tuple<ll, ll, ll>> used;
    que.emplace(calc(0, 0, 0), 0, 0, 0);
    used.emplace(0, 0, 0);
    for (ll i = 0; i < k; ++i) {
        auto [val, x, y, z] = que.top();
        que.pop();
        if (i == k-1) {
            cout << val << endl;
            return 0;
        }
        if (x < n-1 && !used.contains({x+1, y, z})) {
            que.emplace(calc(x+1, y, z), x+1, y, z);
            used.emplace(x+1, y, z);
        }
        if (y < n-1 && !used.contains({x, y+1, z})) {
            que.emplace(calc(x, y+1, z), x, y+1, z);
            used.emplace(x, y+1, z);
        }
        if (z < n-1 && !used.contains({x, y, z+1})) {
            que.emplace(calc(x, y, z+1), x, y, z+1);
            used.emplace(x, y, z+1);
        }
    }

    return 0;
}