#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<ll>> lxy(h), lyx(w), bxy(h), byx(w);
    for (ll i = 0; i < n; ++i) {
        ll ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        lxy[ai].push_back(bi);
        lyx[bi].push_back(ai);
    }
    for (ll i = 0; i < m; ++i) {
        ll ci, di;
        cin >> ci >> di;
        --ci;
        --di;
        bxy[ci].push_back(di);
        byx[di].push_back(ci);
    }
    for (ll i = 0; i < h; ++i) {
        lxy[i].push_back(w+1);
        sort(lxy[i].begin(), lxy[i].end());
        bxy[i].push_back(-1);
        bxy[i].push_back(w);
        sort(bxy[i].begin(), bxy[i].end());
    }
    for (ll j = 0; j < w; ++j) {
        lyx[j].push_back(h+1);
        sort(lyx[j].begin(), lyx[j].end());
        byx[j].push_back(-1);
        byx[j].push_back(h);
        sort(byx[j].begin(), byx[j].end());
    }

    vector<vector<bool>> bright(h, vector<bool>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll k = 0; k < (ll)bxy[i].size() - 1; ++k) {
            if (*lower_bound(lxy[i].begin(), lxy[i].end(), bxy[i][k]) < bxy[i][k+1]) {
                for (ll j = bxy[i][k]+1; j < bxy[i][k+1]; ++j) {
                    bright[i][j] = true;
                }
            }
        }
    }
    for (ll j = 0; j < w; ++j) {
        for (ll k = 0; k < (ll)byx[j].size() - 1; ++k) {
            if (*lower_bound(lyx[j].begin(), lyx[j].end(), byx[j][k]) < byx[j][k+1]) {
                for (ll i = byx[j][k]+1; i < byx[j][k+1]; ++i) {
                    bright[i][j] = true;
                }
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        ans += count(bright[i].begin(), bright[i].end(), true);
    }
    cout << ans << endl;

    return 0;
}