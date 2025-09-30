#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<mint> fact(a+b+c+d+1);
    fact[0] = 1;
    for (ll i = 1; i < (ll)fact.size(); ++i) {
        fact[i] = fact[i-1] * i;
    }

    mint ans = 0;
    for (ll cl = 0; cl <= c; ++cl) {
        mint cur = fact[c-cl+d-1] / (fact[c-cl] * fact[d-1]);
        cur *= fact[b+a+cl] / (fact[b] * fact[a+cl]);
        ans += cur;
    }

    cout << ans.val() << endl;
    return 0;
}