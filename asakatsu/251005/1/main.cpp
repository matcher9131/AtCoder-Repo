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
    unordered_map<ll, ll> a;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        ++a[ai];
    }
    vector<ll> b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }

    for (const ll bi : b) {
        if (!a.contains(bi) || a[bi] <= 0) {
            cout << "No" << endl;
            return 0;
        }
        --a[bi];
    }
    cout << "Yes" << endl;

    return 0;
}