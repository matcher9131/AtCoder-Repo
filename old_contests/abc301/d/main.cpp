#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    ll n;
    cin >> s >> n;
    ll m = s.size();

    string sMax = s, sMin = s;
    for (ll i = 0; i < m; ++i) {
        if (s[i] == '?') {
            sMax[i] = '1';
            sMin[i] = '0';
        }
    }
    ll xMax = stoll(sMax, nullptr, 2), xMin = stoll(sMin, nullptr, 2);
    if (xMax <= n) {
        cout << xMax << endl;
        return 0;
    } else if (n < xMin) {
        cout << -1 << endl;
        return 0;
    }

    ll x = xMin;
    for (ll i = 0; i < m; ++i) {
        if (s[i] != '?') continue;
        ll y = x | (1LL << (m-1-i));
        if (y <= n) x = y;
    }
    cout << x << endl;

    return 0;
}