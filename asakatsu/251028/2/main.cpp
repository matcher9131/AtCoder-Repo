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
    pair<ll, ll> p1, p2;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;

    auto add = [&](pair<ll, ll> v1, pair<ll, ll> v2) -> pair<ll, ll> {
        return { v1.first + v2.first, v1.second + v2.second };
    };
    auto inv = [&](pair<ll, ll> v) -> pair<ll, ll> {
        return { -v.first, -v.second };
    };
    auto rotate = [&](pair<ll, ll> v) -> pair<ll, ll> {
        return { -v.second, v.first };
    };

    auto p3 = add(p2, rotate(add(p2, inv(p1))));
    auto p4 = add(p3, rotate(add(p3, inv(p2))));
    cout << p3.first << " " << p3.second << " " << p4.first << " " << p4.second << endl;

    return 0;
}