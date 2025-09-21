#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll w, h, n;
    cin >> w >> h >> n;

    vector<bool> x(w), y(h);
    while (n--) {
        ll xi, yi, a;
        cin >> xi >> yi >> a;
        if (a == 1) {
            for (ll i = 0; i < xi; ++i) {
                x[i] = true;
            }
        } else if (a == 2) {
            for (ll i = xi; i < w; ++i) {
                x[i] = true;
            }
        } else if (a == 3) {
            for (ll i = 0; i < yi; ++i) {
                y[i] = true;
            }
        } else {
            for (ll i = yi; i < h; ++i) {
                y[i] = true;
            }
        }
    }

    cout << count(x.begin(), x.end(), false) * count(y.begin(), y.end(), false) << endl;

    return 0;
}