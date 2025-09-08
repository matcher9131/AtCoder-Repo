#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    auto isBlack = [&](ll i, ll j) -> bool {
        return i >= 0 && i < h && j >= 0 && j < w && s[i][j] == '#';
    };

    auto getSize = [&](ll i0, ll j0) -> ll {
        ll res = 0;
        while (true) {
            ++res;
            if (!isBlack(i0+res, j0+res)) break;
            if (!isBlack(i0+res, j0-res)) break;
            if (!isBlack(i0-res, j0-res)) break;
            if (!isBlack(i0-res, j0+res)) break;
        }
        --res;
        return res;
    };

    vector<ll> ans(min(h, w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                ll size = getSize(i, j);
                if (size > 0) ++ans[size-1];
            }
        }
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}