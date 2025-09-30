#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;

    vector<bool> isPrime(1e6+1, true);
    isPrime[1] = false;
    for (ll p = 2; p*p <= 1e6; ++p) {
        if (!isPrime[p]) continue;
        for (ll q = 2*p; q <= 1e6; q += p) isPrime[q] = false;
    }

    vector<ll> primes;
    for (ll p = 2; p <= 1e6; ++p) {
        if (isPrime[p]) primes.push_back(p);
    }
    ll m = primes.size();

    ll ans = 0;
    for (ll i = 0; i < m; ++i) {
        ll p = primes[i];
        if (p > n) break;
        
        ll ok = i;
        ll ng = m;
        while (ng - ok > 1) {
            ll mid = (ok+ng) / 2;
            if (primes[mid] * primes[mid] * primes[mid] <= n / p) ok = mid;
            else ng = mid;
        }
        ans += ok - i;
    }

    cout << ans << endl;

    return 0;
}