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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ull, bool>> tests(m);
    for (ll mi = 0; mi < m; ++mi) {
        ll c;
        cin >> c;
        ull bit = 0;
        for (ll ci = 0; ci < c; ++ci) {
            ll aij;
            cin >> aij;
            --aij;
            bit |= 1ULL << aij;
        }
        char ri;
        cin >> ri;
        tests[mi] = { bit, ri == 'o' };
    }

    ll ans = 0;
    for (ull bit = 0; bit < 1ULL<<n; ++bit) {
        bool contradicts = false;
        for (const auto &[pattern, result] : tests) {
            ll numCorrect = popcount(bit & pattern);
            if ((numCorrect < k && result) || (numCorrect >= k && !result)) {
                contradicts = true;
                break;
            }
        }
        if (!contradicts) ++ans;
    }
    cout << ans << endl;

    return 0;
}