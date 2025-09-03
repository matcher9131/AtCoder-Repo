#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;

    if (m < 0) {
        cout << -1 << endl;
    } else if (m == 0) {
        for (ll i = 0; i < n; ++i) {
            cout << 1'000'000 + 2*i + 1 << " " << 1'000'000 + 2*i + 2 << endl;
        }
    } else {
        if (m >= n-1) {
            cout << -1 << endl;
        } else {
            cout << 1 << " " << 1'000'000 << endl;
            for (ll i = 0; i < m+1; ++i) {
                cout << 2*i+2 << " " << 2*i+3 << endl;
            }
            for (ll i = 0; i < n - (m+2); ++i) {
                cout << 1'000'000 + 2*i + 1 << " " << 1'000'000 + 2*i + 2 << endl;
            }
        }
    }

    return 0;
}