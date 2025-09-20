#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

void solve() {
    ll h, w;
    cin >> h >> w;
    ull master = 0;
    for (ll i = 0; i < h; ++i) {
        string si;
        cin >> si;
        for (ll j = 0; j < w; ++j) {
            if (si[j] == '#') master |= 1ULL << (i*w+j);
        }
    }
    ull mask = (1ULL << (w+1)) - 1ULL;

    vector<vector<ll>> dp(h*w, vector<ll>(1<<(w+1), INF));

    // 
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}