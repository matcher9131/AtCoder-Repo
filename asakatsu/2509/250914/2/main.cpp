#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

ll intPow(ll x, ll y) {
    ll ans = 1;
    for (ll i = 0; i < y; ++i) {
        ans *= x;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;

    for (ll b = 1; b <= 25; ++b) {
        ll m = n - intPow(5, b);
        if (m < 3) break;
        ll a = 0;
        while (m % 3 == 0) {
            m /= 3;
            ++a;
        }
        if (m == 1) {
            cout << a << " " << b << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}