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
    string s;
    cin >> s;

    vector<ll> c(6);
    for (const char ch : s) {
        ++c[ch - 'A'];
    }

    for (ll i = 0; i < (ll)c.size(); ++i) {
        cout << c[i] << " \n"[i == (ll)c.size() - 1];
    }

    return 0;
}