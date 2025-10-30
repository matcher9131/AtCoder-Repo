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
    ll n;
    cin >> n;
    vector<ll> x(n), y(n), h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> h[i];
    }
    ll highestIndex = max_element(h.begin(), h.end()) - h.begin();

    auto isOK = [&](ll cx, ll cy, ll H) {
        for (ll i = 0; i < n; ++i) {
            if (h[i] != max(H - abs(x[i] - cx) - abs(y[i] - cy), 0LL)) return false;
        }
        return true;
    };

    for (ll cx = 0; cx <= 100; ++cx) {
        for (ll cy = 0; cy <= 100; ++cy) {
            ll H = h[highestIndex] + abs(x[highestIndex] - cx) + abs(y[highestIndex] - cy);
            if (isOK(cx, cy, H)) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }

    return 0;
}