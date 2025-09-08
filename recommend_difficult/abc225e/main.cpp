#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    // end, start
    vector<pair<long double, long double>> seg(n);
    for (ll i = 0; i < n; ++i) {
        long double xi, yi;
        cin >> xi >> yi;
        long double start = (yi-1) / xi;
        long double end = yi / (xi-1);
        seg[i] = { end, start };
    }
    sort(seg.begin(), seg.end());

    ll ans = 0;
    long double last_end = 0;
    for (const auto &[end, start] : seg) {
        if (start >= last_end) {
            ++ans;
            last_end = end;
        }
    }

    cout << ans << endl;
    return 0;
}