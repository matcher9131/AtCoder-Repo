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
    vector<string> s(8);
    for (ll i = 0; i < 8; ++i) {
        cin >> s[i];
    }

    unordered_set<ll> r, c;
    for (ll i = 0; i < 8; ++i) {
        for (ll j = 0; j < 8; ++j) {
            if (s[i][j] == '#') {
                r.insert(i);
                c.insert(j);
            }
        }
    }

    cout << (8 - r.size()) * (8 - c.size()) << endl;

    return 0;
}