#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

vector<pair<ll, ll>> factorize(ll x, const vector<ll> &minFactor) {
    vector<pair<ll, ll>> res;
    while (x > 1) {
        ll p = minFactor[x];
        ll e = 0;
        while (minFactor[x] == p) {
            x /= p;
            ++e;
        }
        res.emplace_back(p, e);
    }
    return res;
}

void solve(const vector<ll> &minFactor) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<ll, ll>>> factorized(n);
    for (ll i = 0; i < n; ++i) {
        factorized[i] = factorize(a[i], minFactor);
    }

    unordered_map<ll, vector<pair<ll, ll>>> factorMap;
    for (ll i = 0; i < n; ++i) {
        for (const auto &[p, e] : factorized[i]) {
            factorMap[p].emplace_back(e, i);
            sort(factorMap[p].begin(), factorMap[p].end(), greater<>());
            if (factorMap[p].size() > 2) factorMap[p].resize(2);
        }
    }

    mint lcd = 1;
    for (const auto &[p, x] : factorMap) {
        lcd *= mint(p).pow(x[0].first);
    }

    vector<mint> ans(n, lcd);
    for (ll i = 0; i < n; ++i) {
        for (const auto &[p, e] : factorized[i]) {
            if (factorMap[p][0].second == i) {
                ll secondExp = factorMap[p].size() > 1 ? factorMap[p][1].first : 0;
                ans[i] /= mint(p).pow(factorMap[p][0].first - secondExp);
            }
        }
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i].val() << " \n"[i == (ll)ans.size() - 1];
    }
}

int main() {
    ll m = 1e7;
    vector<bool> isPrime(m+1, true);
    vector<ll> minFactor(m+1, -1);
    isPrime[1] = false;
    minFactor[1] = 1;
    for (ll p = 2; p <= m; ++p) {
        if (!isPrime[p]) continue;
        minFactor[p] = p;
        for (ll q = 2*p; q <= m; q += p) {
            isPrime[q] = false;
            if (minFactor[q] == -1) minFactor[q] = p;
        }
    }

    ll t;
    cin >> t;
    
    while (t--) {
        solve(minFactor);
    }

    return 0;
}