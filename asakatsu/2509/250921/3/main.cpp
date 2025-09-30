#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;

    ll m = ([&](ll x) -> ll {
        ll res = 0;
        while (x > 0) {
            x /= 10;
            ++res;
        }
        return res;
    })(n);
    mint ans = 0;
    mint base10 = 10;
    for (ll i = 0; i < m-1; ++i) {
        ans += (1 + base10.pow(i+1) - base10.pow(i)) * (base10.pow(i+1) - base10.pow(i)) / 2;
    }
    ans += (1 + n - base10.pow(m-1) + 1) * (n - base10.pow(m-1) + 1) / 2;
    cout << ans.val() << endl;

    return 0;
}