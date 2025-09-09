#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    set<pair<ll, ll>> black;
    set<pair<ll, ll>> target;
    for (ll i = 0; i < n; ++i) {
        ll ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        black.emplace(ai, bi);
        for (ll ci = ai-2; ci <= ai; ++ci) {
            if (ci < 0 || ci+2 >= h) continue;
            for (ll di = bi-2; di <= bi; ++di) {
                if (di < 0 || di+2 >= w) continue;
                target.emplace(ci, di);
            }
        }
    }

    vector<ll> ans(10);
    for (const auto &[i0, j0] : target) {
        ll count = 0;
        for (ll i = i0; i < i0+3; ++i) {
            for (ll j = j0; j < j0+3; ++j) {
                if (black.contains({i, j})) ++count;
            }
        }
        ++ans[count];
    }
    
    ans[0] = (h-2) * (w-2);
    for (ll i = 1; i < 10; ++i) {
        ans[0] -= ans[i];
    }

    for (ll i = 0; i < 10; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}