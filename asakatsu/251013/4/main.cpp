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
    ll t;
    cin >> t;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    vector<ll> b(m);
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    for (ll i = 0; i < n; ++i) {
        que.emplace(a[i], 0);
    }
    for (ll j = 0; j < m; ++j) {
        que.emplace(b[j], 1);
    }
    queue<ll> stock;

    while (!que.empty()) {
        auto [ti, k] = que.top();
        que.pop();
        if (k == 0) stock.push(ti);
        else {
            while (!stock.empty()) {
                ll tti = stock.front();
                if (tti + t < ti) stock.pop();
                else break;
            }
            if (stock.empty()) {
                cout << "no" << endl;
                return 0;
            } else {
                stock.pop();
            }
        }
    }
    cout << "yes" << endl;

    return 0;
}