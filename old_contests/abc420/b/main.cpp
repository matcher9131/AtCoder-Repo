#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<ll> c(n);
    for (ll j = 0; j < m; ++j) {
        ll x = 0, y = 0;
        for (ll i = 0; i < n; ++i) {
            if (s[i][j] == '0') ++x;
            else ++y;
        }

        if (x == 0 || y == 0) {
            for (ll i = 0; i < n; ++i) {
                ++c[i];
            }
        } else if (x < y) {
            for (ll i = 0; i < n; ++i) {
                if (s[i][j] == '0') ++c[i];
            }
        } else {
            for (ll i = 0; i < n; ++i) {
                if (s[i][j] == '1') ++c[i];
            }
        }
    }

    ll cMax = *max_element(c.begin(), c.end());
    vector<ll> ans;
    for (ll i = 0; i < n; ++i) {
        if (c[i] == cMax) ans.push_back(i);
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] + 1 << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}