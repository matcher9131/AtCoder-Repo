#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

vector<ll> dic{ 6, 2, 4, 8 };

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    if (n >= m-1 && k == m-1) {
        cout << 0 << endl;
    } else if (n < m) {
        cout << dic[n % 4] << endl;
    } else {
        ll i = (n - k) / (m - k);
        ll r = n - i * (m - k);
        cout << dic[r % 4] << endl;
    }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}
