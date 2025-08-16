#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<mint> fact(h*w+1);
    fact[0] = 1;
    for (ll i = 1; i <= h*w; ++i) {
        fact[i] = fact[i-1] * i;
    }
    auto comb = [&](ll n, ll r) -> mint {
        if (n < r) return 0;
        return fact[n] / (fact[r] * fact[n-r]);
    };

    mint ans = 0;
    for (ll x = 1; x <= h; ++x) {
        for (ll y = 1; y <= w; ++y) {
            if (x*y < k) continue;
            mint all = comb(x*y, k);
            // A, ...
            mint numCases = 2 * (all - comb((x-1)*y, k)) + 2 * (all - comb(x*(y-1), k));
            // A∪B, ...
            numCases -= (all - comb(x*(y-2), k)) + 4 * (all - comb((x-1)*(y-1), k)) + (all - comb((x-2)*y, k));
            // A∪B∪C, ...
            numCases += 2 * (all - comb((x-1)*(y-2), k)) + 2 * (all - comb((x-2)*(y-1), k));
            // A∪B∪C∪D
            numCases -= all - comb((x-2)*(y-2), k);
            ans += numCases * (h+1 - x) * (w+1 - y) * x * y;
        }
    }
    ans /= comb(h*w, k);

    cout << ans.val() << endl;

    return 0;
}