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
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    vector<pair<int, int>> dir = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    auto isBlack = [&](ll i, ll j) -> bool {
        if (s[i][j] == '.') return false;
        for (const auto &[di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (s[ni][nj] == '.') return false;
        }
        return true;
    };

    vector<string> ans(h, string(w, '.'));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (isBlack(i, j)) ans[i][j] = '#';
        }
    }

    vector<string> check(h, string(w, '.'));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (ans[i][j] == '#') {
                check[i][j] = '#';
                for (const auto &[di, dj] : dir) {
                    ll ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                    check[ni][nj] = '#';
                }
            }
        }
    }

    if (check == s) {
        cout << "possible" << endl;
        for (ll i = 0; i < h; ++i) {
            cout << ans[i] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}