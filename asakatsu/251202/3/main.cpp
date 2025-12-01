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
    unordered_set<ll> a, b;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a.insert(ai);
    }
    for (ll j = 0; j < m; ++j) {
        ll bi;
        cin >> bi;
        b.insert(bi);
    }

    ll cross = 0;
    for (const ll &ai : a) {
        if (b.contains(ai)) ++cross;
    }
    cout << fixed << setprecision(15) << (double)cross / (n + m - cross) << endl;

    return 0;
}