#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll t, m;
    cin >> t >> m;
    
    vector<bool> isPrime(5001, true);
    vector<ll> minFactor(5001, -1);
    isPrime[1] = false;
    minFactor[1] = 1;
    for (ll p = 2; p <= 5000; ++p) {
        if (!isPrime[p]) continue;
        minFactor[p] = p;
        for (ll q = 2*p; q <= 5000; q += p) {
            isPrime[q] = false;
            if (minFactor[q] == -1) minFactor[q] = p;
        }
    }

    vector<unordered_map<ll, ll>> factorized(5001);
    for (ll x = 2; x <= 5000; ++x) {
        factorized[x] = factorized[x-1];
        ll y = x;
        while (y>1) {
            ll p = minFactor[y];
            while (minFactor[y] == p) {
                y /= p;
                ++factorized[x][p];
            }
        }
    }

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> c(n);
        for (ll i = 0; i < n; ++i) {
            cin >> c[i];
        }
        ll s = accumulate(c.begin(), c.end(), 0LL);

        unordered_map<ll, ll> fact = factorized[s];
        for (ll i = 0; i < n; ++i) {
            for (const auto &[p, cnt] : factorized[c[i]]) {
                fact[p] -= cnt;
            }
        }

        ll ans = 1;
        for (const auto &[p, cnt] : fact) {
            ans = ans * atcoder::pow_mod(p, cnt, m) % m;
        }
        cout << ans << endl;
    }

    return 0;
}