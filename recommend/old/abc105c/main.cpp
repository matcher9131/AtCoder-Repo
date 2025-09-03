#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    string ans;
    for (ll i = 0; i < 35; ++i) {
        if (n == 0) break;
        if (abs(n) & (1LL << i)) {
            n -= (1LL << i) * (i % 2 ? -1 : 1);
            ans += '1';
        } else {
            ans += '0';
        }
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}