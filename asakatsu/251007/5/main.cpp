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
    ll a, b;
    cin >> a >> b;

    vector<pair<ll, ll>> factorized;
    for (ll p = 2; p*p <= a; ++p) {
        ll e = 0;
        while (a%p == 0) {
            a /= p;
            ++e;
        }
        if (e > 0) factorized.emplace_back(p, e);
    }
    if (a > 1) factorized.emplace_back(a, 1);

    mint prod = 1;
    for (const auto &[_, e] : factorized) {
        prod *= mint(b) * e + 1;
    }
    
    if (b%2 && all_of(factorized.begin(), factorized.end(), [](pair<ll, ll> &t) { return t.second % 2 == 0; })) {
        mint ans = (prod * b - 1) / 2;
        cout << ans.val() << endl;
    } else {
        mint ans = prod * b / 2;
        cout << ans.val() << endl;
    }

    return 0;
}