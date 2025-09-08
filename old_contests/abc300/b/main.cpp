#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (ll i = 0; i < h; ++i) {
        cin >> a[i];
    }
    vector<string> b(h);
    for (ll i = 0; i < h; ++i) {
        cin >> b[i];
    }

    auto match = [&](ll i0, ll j0) -> bool {
        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (a[i][j] != b[(i0+i)%h][(j0+j)%w]) return false;
            }
        }
        return true;
    };

    for (ll i0 = 0; i0 < h; ++i0) {
        for (ll j0 = 0; j0 < w; ++j0) {
            if (match(i0, j0)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}