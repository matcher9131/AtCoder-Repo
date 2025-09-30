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
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    
    set<pair<ll, ll>> g;
    g.emplace(a[0], b[0]);
    for (ll i = 1; i < n; ++i) {
        set<pair<ll, ll>> g2;
        for (const auto &[ga, gb] : g) {
            g2.emplace(gcd(ga, a[i]), gcd(gb, b[i]));
            g2.emplace(gcd(ga, b[i]), gcd(gb, a[i]));
        }
        swap(g, g2);
    }

    ll ans = 1;
    for (const auto &[ga, gb] : g) {
        ans = max(ans, ga * gb / gcd(ga, gb));
    }

    cout << ans << endl;
    return 0;
}