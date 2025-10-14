#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<unordered_map<ll, ll>> former(n);
    for (ull bit = 0; bit < (1ULL << (n-1)); ++bit) {
        ll x = a[0][0], i = 0, j = 0;
        for (ll bi = 0; bi < n-1; ++bi) {
            if (bit & (1ULL << bi)) ++j;
            else ++i;
            x ^= a[i][j];
        }
        ++former[i][x];
    }

    vector<unordered_map<ll, ll>> latter(n);
    for (ull bit = 0; bit < (1ULL << (n-1)); ++bit) {
        ll x = a[n-1][n-1], i = n-1, j = n-1;
        for (ll bi = 0; bi < n-1; ++bi) {
            if (bit & (1ULL << bi)) --j;
            else --i;
            x ^= a[i][j];
        }
        x ^= a[i][j];
        ++latter[i][x];
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (const auto &[xf, cf] : former[i]) {
            ans += cf * latter[i][xf];
        }
    }

    cout << ans << endl;

    return 0;
}

// 527ms
