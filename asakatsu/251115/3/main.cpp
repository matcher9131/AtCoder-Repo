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
    ll n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<ll, ll>> item;
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        item.emplace(x, y);
    }

    ll x = 0, y = 0;
    for (const char c : s) {
        if (c == 'R') ++x;
        else if (c == 'L') --x;
        else if (c == 'U') ++y;
        else --y;

        --h;
        if (h < 0) {
            cout << "No" << endl;
            return 0;
        }
        if (h < k && item.contains({x, y})) {
            item.erase({x, y});
            h = k;
        }
    }
    cout << "Yes" << endl;

    return 0;
}