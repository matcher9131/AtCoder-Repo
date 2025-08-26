#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, d;
    cin >> n >> d;

    mint m2 = 2;

    mint ans = 0;
    for (ll lv = 0; lv < n; ++lv) {
        // LCAがiまたはjに一致
        mint p = lv + d > n-1 ? 0 : m2.pow(d);
        // LCAがiまたはjに一致しない
        ll kMin = lv + d - n + 1;
        ll kMax = n - 1 - lv;
        kMin = max(kMin, 1LL);
        kMax = min(kMax, d-1);
        if (kMin <= kMax) p += (kMax - kMin + 1) * m2.pow(d-2);

        ans += m2.pow(lv) * p;
    }
    ans *= 2;

    cout << ans.val() << endl;
    return 0;
}