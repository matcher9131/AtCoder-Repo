#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    string s;
    cin >> n >> s;

    ll ans = -1;
    ll left = -1;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '-') {
            ans = max(ans, i - left - 1);
            left = i;
        }
    }
    ans = max(ans, n - left - 1);
    if (ans == n || ans == 0) ans = -1;

    cout << ans << endl;
    return 0;
}