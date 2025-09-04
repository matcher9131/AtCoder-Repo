#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    auto getNumCut = [&](vector<ll> &border) -> ll {
        vector<vector<ll>> sum(border.size(), vector<ll>(w+1));
        for (ll j = 0; j < w; ++j) {
            ll i = 0;
            for (ll gi = 0; gi < (ll)border.size(); ++gi) {
                sum[gi][j+1] = sum[gi][j];
                for (; i <= border[gi]; ++i) {
                    sum[gi][j+1] += s[i][j] - '0';
                }
            }
        }

        ll res = 0;
        ll left = 0;
        while (left < w) {
            ll minRight = INF;
            for (ll gi = 0; gi < (ll)border.size(); ++gi) {
                ll right = upper_bound(sum[gi].begin(), sum[gi].end(), sum[gi][left] + k) - sum[gi].begin();
                --right;
                minRight = min(minRight, right);
            }
            if (minRight == left) return -1;
            ++res;
            left = minRight;
        }
        return res - 1;
    };

    ll ans = INF;
    for (ull bit = 0; bit < 1ULL << (h-1); ++bit) {
        vector<ll> border;
        for (ll i = 0; i < h-1; ++i) {
            if (bit & (1ULL << i)) border.push_back(i);
        }
        border.push_back(h-1);

        ll numCut = getNumCut(border);
        if (numCut == -1) continue;
        ans = min(ans, (ll)popcount(bit) + numCut);
    }

    cout << ans << endl;
    return 0;
}