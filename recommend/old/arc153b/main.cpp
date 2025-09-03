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

    // s[0][0]の場所
    ll i0 = 0, j0 = 0;
    ll nq;
    cin >> nq;
    ll dir = nq % 2 == 0 ? 1 : -1;
    while (nq--) {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        i0 = i0 > a ? h + a - i0 : a - i0;
        j0 = j0 > b ? w + b - j0 : b - j0;
    }

    vector<string> t(h, string(w, '_'));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            ll ti = (i0 + dir * i + h) % h;
            ll tj = (j0 + dir * j + w) % w;
            t[ti][tj] = s[i][j];
        }
    }

    for (ll i = 0; i < h; ++i) {
        cout << t[i] << endl;
    }
    return 0;
}