#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;

    for (ll i = 1; i <= 15; ++i) {
        ll x = 1;
        for (ll j = 0; j < i; ++j) {
            x *= i;
        }
        if (n == x) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}