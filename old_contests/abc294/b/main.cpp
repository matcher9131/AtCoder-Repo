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
        for (ll j = 0; j < w; ++j) {
            ll aij;
            cin >> aij;
            if (aij == 0) s[i] += '.';
            else s[i] += aij - 1 + 'A';
        }
    }

    for (ll i = 0; i < h; ++i) {
        cout << s[i] << endl;
    }
    
    return 0;
}