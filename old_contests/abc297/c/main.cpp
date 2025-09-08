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

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w-1; ++j) {
            if (s[i][j] == 'T' && s[i][j+1] == 'T') {
                s[i][j] = 'P';
                s[i][j+1] = 'C';
            }
        }
    }

    for (ll i = 0; i < h; ++i) {
        cout << s[i] << endl;
    }

    return 0;
}