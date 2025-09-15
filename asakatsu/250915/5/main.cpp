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
    vector<vector<ll>> a(n, vector<ll>(n-1));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n-1; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }

    vector<vector<ll>> g(n*n);
    vector<vector<ll>> inDeg(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n-2; ++j) {
            ll u1 = i, u2 = a[i][j];
            if (u1 > u2) swap(u1, u2);
            ll v1 = i, v2 = a[i][j+1];
            if (v1 > v2) swap(v1, v2);
            g[u1*n+u2].push_back(v1*n+v2);
            ++inDeg[v1][v2];
        }
    }

    set<pair<ll, ll>> source;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            if (inDeg[i][j] == 0) source.emplace(i, j);
        }
    }

    ll ans = 0;
    ll done = 0;
    while (!source.empty()) {
        ++ans;
        set<pair<ll, ll>> source2;
        for (const auto &[i, j] : source) {
            ++done;
            for (const ll to : g[i*n+j]) {
                --inDeg[to/n][to%n];
                if (inDeg[to/n][to%n] == 0) source2.emplace(to/n, to%n);
            }
        }
        swap(source, source2);
    }

    cout << (done == n * (n-1) / 2 ? ans : -1) << endl;

    return 0;
}