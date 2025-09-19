#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    string s;
    cin >> s;
    ll n = s.size();

    vector<ll> c(3);
    ll r = 0;
    for (ll i = 0; i < n; ++i) {
        ll ri = (s[i] - '0') % 3;
        ++c[ri];
        r += ri;
    }
    r %= 3;

    if (r == 0) cout << 0 << endl;
    else if (r == 1) {
        if (c[1] >= 1 && n >= 2) cout << 1 << endl;
        else if (c[2] >= 2 && n >= 3) cout << 2 << endl;
        else cout << -1 << endl;
    } else {
        if (c[2] >= 1 && n >= 2) cout << 1 << endl;
        else if (c[1] >= 2 && n >= 3) cout << 2 << endl;
        else cout << -1 << endl;
    }

    return 0;
}