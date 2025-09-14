#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll x = 0;
    for (const ll ai : a) {
        ll grundy = (ai % (l+r)) / l;
        x ^= grundy;
    }

    cout << (x == 0 ? "Second" : "First") << endl;

    return 0;
}