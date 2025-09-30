#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    vector<ll> a(4);
    for (ll i = 0; i < 4; ++i) {
        cin >> a[i];
    }
    ll n;
    cin >> n;

    vector<ll> b{8*a[0], 4*a[1], 2*a[2], a[3]};
    ll bMin = *min_element(b.begin(), b.end());

    vector<ll> c{4*a[0], 2*a[1], a[2]};
    ll cMin = *min_element(c.begin(), c.end());

    ll ans = (n/2) * bMin + (n%2) * cMin;
    cout << ans << endl;

    return 0;
}