#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<string> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    // c[x][y]: a_i = k・5^(x-10)・2^(y-10)となるiの個数
    constexpr ll xMax = 20, yMax = 60;
    vector<atcoder::fenwick_tree<ll>> c(xMax, atcoder::fenwick_tree<ll>(60));
    for (ll i = 0; i < n; ++i) {
        auto pos = a[i].find('.');
        ll x = pos == string::npos ? 0 : -(ll)a[i].size() + (ll)pos + 1;
        ll y = x;
        ll ai = stoll(pos == string::npos ? a[i] : a[i].substr(0, pos) + a[i].substr(pos + 1));
        while (ai % 5 == 0) {
            ai /= 5;
            ++x;
        }
        while (ai % 2 == 0) {
            ai /= 2;
            ++y;
        }

        for (ll x2 = 0; x2 < xMax; ++x2) {
            if (x + x2-10 < 0) continue;
            ans += c[x2].sum(max(0LL, -y+10), yMax);
        }

        c[x+10].add(y+10, 1);
    }

    cout << ans << endl;

    return 0;
}