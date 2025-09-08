#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll grundy = 0;
    for (ll i = 0; i < n; ++i) {
        grundy ^= (a[i] % (l+r)) / l;
    }

    cout << (grundy ? "First" : "Second") << endl;

    return 0;
}