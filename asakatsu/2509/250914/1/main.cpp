#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    map<ll, ll> x, y;
    for (ll i = 0; i < 3; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        ++x[xi];
        ++y[yi];
    }

    ll ansX = 0, ansY = 0;
    for (const auto &[v, c] : x) {
        if (c == 1) ansX = v;
    }
    for (const auto &[v, c] : y) {
        if (c == 1) ansY = v;
    }

    cout << ansX << " " << ansY << endl;

    return 0;
}