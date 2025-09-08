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
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    auto explode = [&](ll i0, ll j0, ll r) -> void {
        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (i == i0 && j == j0) continue;
                if (s[i][j] == '#' && abs(i - i0) + abs(j - j0) <= r) s[i][j] = '.';
            }
        }
    };

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] - '0' >= 0 && s[i][j] - '0' <= 9) {
                explode(i, j, s[i][j] - '0');
                s[i][j] = '.';
            }
        }
    }

    for (ll i = 0; i < h; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}