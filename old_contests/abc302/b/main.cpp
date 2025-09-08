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

    string sample = "snuke";
    auto isSnuke = [&](int i0, int j0, int di, int dj) -> bool {
        for (ll k = 0; k < 5; ++k) {
            int i = i0 + k * di;
            int j = j0 + k * dj;
            if (i < 0 || i >= h || j < 0 || j >= w || s[i][j] != sample[k]) return false; 
        }
        return true;
    };

    vector<pair<int, int>> dir{
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {-1, 0},
        {-1, -1},
        {0, -1},
        {1, -1}
    };
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] != 's') continue;
            for (const auto &[di, dj] : dir) {
                if (isSnuke(i, j, di, dj)) {
                    for (ll k = 0; k < 5; ++k) {
                        cout << i + k * di + 1 << " " << j + k * dj + 1 << endl;
                    }
                    return 0;
                }
            }
        }
    }

    return 0;
}