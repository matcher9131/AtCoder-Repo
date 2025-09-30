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
    ll n, nq;
    cin >> n >> nq;
    unordered_map<ll, vector<ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a[ai].push_back(i);
    }

    while (nq--) {
        ll x, k;
        cin >> x >> k;
        --k;
        if (!a.contains(x) || (ll)a[x].size() <= k) {
            cout << -1 << endl;
        } else {
            cout << a[x][k] + 1 << endl;
        }
    }

    return 0;
}