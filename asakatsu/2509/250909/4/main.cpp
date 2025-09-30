#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector<ll> ans(1 << (h*w), -1);
    ans[0] = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            ans[0] ^= a[i][j];
        }
    }

    function<void(ll, ll)> dfs = [&](ll bit, ll val) -> void {
        ans[bit] = val;
        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                ll thisBit = 1 << (i*w+j);
                if (bit & thisBit) continue;
                ll bottomBit = 1 << ((i+1)*w+j);
                ll rightBit = 1 << (i*w+j+1);
                if (i < h-1 && (bit & bottomBit) == 0) {
                    ll newBit = bit | thisBit | bottomBit;
                    if (ans[newBit] == -1) dfs(newBit, val ^ a[i][j] ^ a[i+1][j]);
                }
                if (j < w-1 && (bit & rightBit) == 0) {
                    ll newBit = bit | thisBit | rightBit;
                    if (ans[newBit] == -1) dfs(newBit, val ^ a[i][j] ^ a[i][j+1]);
                }
            }
        }
    };
    dfs(0, ans[0]);

    cout << *max_element(ans.begin(), ans.end()) << endl;


    return 0;
}