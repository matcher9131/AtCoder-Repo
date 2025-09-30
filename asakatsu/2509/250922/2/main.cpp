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
    string s;
    cin >> s;

    ll ans = 0;
    for (ll i = 1; i < n-1; ++i) {
        vector<ll> c1(26), c2(26);
        for (ll j = 0; j < i; ++j) {
            ++c1[s[j] - 'a'];
        }
        for (ll j = i; j < n; ++j) {
            ++c2[s[j] - 'a'];
        }
        ll count = 0;
        for (ll k = 0; k < 26; ++k) {
            if (c1[k] > 0 && c2[k] > 0) ++count;
        }
        ans = max(ans, count);
    }

    cout << ans << endl;
    return 0;
}