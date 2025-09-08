#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector<ll> dir;
    for (ll i = 0; i < h-1; ++i) {
        dir.push_back(0);
    }
    for (ll j = 0; j < w-1; ++j) {
        dir.push_back(1);
    }

    ll ans = 0;
    do {
        set<ll> s;
        s.insert(a[0][0]);
        ll i = 0, j = 0;
        for (const ll d : dir) {
            if (d == 1) ++j;
            else ++i;
            s.insert(a[i][j]);
        }
        if ((ll)s.size() == h+w-1) ++ans;
    } while (next_permutation(dir.begin(), dir.end()));

    cout << ans << endl;
    return 0;
}