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
    
    vector<bool> is_prime(5001, true);
    vector<ll> min_factor(5001, -1);
    is_prime[1] = false;
    min_factor[1] = 1;
    for (ll p = 2; p <= 5000; ++p) {
        if (!is_prime[p]) continue;
        min_factor[p] = p;
        for (ll q = 2*p; q <= 5000; q += p) {
            is_prime[q] = false;
            if (min_factor[q] == -1) min_factor[q] = p;
        }
    }

    // n!の素因数分解結果
    vector<unordered_map<ll, ll>> factorized(5001);
    for (ll x = 2; x <= 5000; ++x) {
        factorized[x] = factorized[x-1];
        ll y = x;
        while (y>1) {
            ll p = min_factor[y];
            while (min_factor[y] == p) {
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

// 1884ms
