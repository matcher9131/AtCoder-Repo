#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    map<ull, ll> m;
    for (ll i = 0; i < n; ++i) {
        ull ai;
        cin >> ai;
        ++m[ai];
    }

    ll ans = 0;
    while (!m.empty()) {
        auto [val, _] = *m.rbegin();
        --m[val];
        if (m[val] == 0) m.erase(val);
        ull other = val == bit_ceil(val) ? val : bit_ceil(val) - val;
        if (m.contains(other) && m[other] > 0) {
            ++ans;
            --m[other];
            if (m[other] == 0) m.erase(other);
        }
    }

    cout << ans << endl;
    return 0;
}