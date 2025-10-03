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
    vector<tuple<ll, ll, ll>> bomb;
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
        for (ll j = 0; j < w; ++j) {
            if ('1' <= s[i][j] && s[i][j] <= '9') bomb.emplace_back(i, j, s[i][j] - '0');
        }
    }

    auto destroy = [&](ll i, ll j) -> void {
        for (const auto &[x, y, r] : bomb) {
            ll d = abs(x-i) + abs(y-j);
            if (d <= r) {
                s[i][j] = '.';
                break;
            }
        }
    };

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') destroy(i, j);
            else s[i][j] = '.';
        }
    }

    for (ll i = 0; i < h; ++i) {
        cout << s[i] << endl;
    }

    return 0;
}