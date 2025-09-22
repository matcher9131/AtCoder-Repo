#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h, w, k, n;
    cin >> h >> w >> k >> n;
    unordered_map<ll, unordered_set<ll>> candy;
    vector<ll> sr(h);
    vector<ll> sc(w);
    for (ll i = 0; i < n; ++i) {
        ll ri, ci;
        cin >> ri >> ci;
        --ri;
        --ci;
        candy[ri].insert(ci);
        ++sr[ri];
        ++sc[ci];
    }

    unordered_map<ll, ll> scMap;
    for (const ll sci : sc) {
        ++scMap[sci];
    }

    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        if (sr[i] > k) continue;
        ll rest = k - sr[i];
        ans += scMap[rest];
        for (const auto j : candy[i]) {
            ll sum = sr[i] + sc[j];
            if (sum == k+1) ++ans;
            else if (sum == k) --ans;
        }
    }
    cout << ans << endl;

    return 0;
}