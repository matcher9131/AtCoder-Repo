#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<ll> s;
    s.reserve(n * (n+1) / 2);
    for (ll i = 0; i < n; ++i) {
        ll sum = 0;
        for (ll j = i; j < n; ++j) {
            sum += a[j];
            s.push_back(sum);
        }
    }

    ll ans = 0;
    for (ll bi = 39; bi >= 0; --bi) {
        ll mask = ans | (1LL << bi);
        ll count = 0;
        for (ll i = 0; i < (ll)s.size(); ++i) {
            if ((s[i] & mask) == mask) ++count;
        }
        if (count >= k) ans = mask;
    }

    cout << ans << endl;
    return 0;
}