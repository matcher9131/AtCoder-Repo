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
    vector<pair<ll, ll>> med(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> med[i].first >> med[i].second;
        sum += med[i].second;
    }
    sort(med.begin(), med.end());

    if (sum <= k) {
        cout << 1 << endl;
        return 0;
    }
    for (const auto &[ai, bi] : med) {
        sum -= bi;
        if (sum <= k) {
            cout << ai+1 << endl;
            return 0;
        }
    }

    return 0;
}