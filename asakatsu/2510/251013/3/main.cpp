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

    unordered_set<ll> prev{ a[0], b[0] };
    for (ll i = 1; i < n; ++i) {
        unordered_set<ll> cur;
        for (const ll p : prev) {
            if (abs(a[i] - p) <= k) cur.insert(a[i]);
            if (abs(b[i] - p) <= k) cur.insert(b[i]);
        }
        if (cur.empty()) {
            cout << "No" << endl;
            return 0;
        }
        swap(prev, cur);
    }
    cout << "Yes" << endl;

    return 0;
}