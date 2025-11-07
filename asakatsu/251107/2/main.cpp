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

    vector<unordered_set<ll>> ng(n);
    vector<bool> single(n);
    for (ll ki = 0; ki < k; ++ki) {
        char c;
        ll j;
        cin >> c >> j;
        --j;
        single[j] = true;
        if (c == 'L') {
            for (ll i = 0; i < j; ++i) {
                ng[i].insert(ki);
            }
        } else {
            for (ll i = n-1; i > j; --i) {
                ng[i].insert(ki);
            }
        }
    }

    mint ans = 1;
    for (ll i = 0; i < n; ++i) {
        if (single[i]) continue;
        ans *= k - ng[i].size();
    }
    cout << ans.val() << endl;

    return 0;
}