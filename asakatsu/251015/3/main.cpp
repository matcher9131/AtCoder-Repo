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
    vector<ll> c(2e5);
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        --ai;
        ++c[ai];
    }

    vector<ll> c2;
    for (ll i = 0; i < 2e5; ++i) {
        if (c[i] > 0) c2.push_back(c[i]);
    }
    ll m = c2.size();
    if (m <= k) {
        cout << 0 << endl;
        return 0;
    }
    sort(c2.begin(), c2.end());
    cout << accumulate(c2.begin(), c2.begin() + m - k, 0LL) << endl;

    return 0;
}