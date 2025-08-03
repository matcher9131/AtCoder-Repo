#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;

    ll m = 3e5;
    vector<ll> isPrime(m, true);
    isPrime[0] = isPrime[1] = false;
    for (ll d = 2; d < m; ++d) {
        if (!isPrime[d]) continue;
        for (ll x = 2*d; x < m; x += d) {
            isPrime[x] = false;
        }
    }

    vector<ll> prime;
    for (ll i = 0; i < m; ++i) {
        if (isPrime[i]) prime.push_back(i);
    }

    ll bMax = pow(n / 4, 1.0 / 3);
    ll ans = 0;
    for (ll j = 1; j < (ll)prime.size(); ++j) {
        ll b = prime[j];
        if (b > bMax) break;
        for (ll i = 0; i < j; ++i) {
            ll a = prime[i];
            ll cMax = sqrt(n / a / a / b);
            if (cMax < b) break;
            ans += upper_bound(prime.begin(), prime.end(), cMax) - prime.begin() - (j+1);
        }
    }
    
    cout << ans << endl;

    return 0;
}