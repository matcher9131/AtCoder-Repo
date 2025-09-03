#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    ll sqrtn = sqrt(n);

    mint ans = 0;
    for (ll i = 1; i <= sqrtn; ++i) {
        ll upper = n / i;
        ll count = (upper - i) / 2 + 1;
        ans += count;
    }

    cout << ans.val() << endl;
    return 0;
}