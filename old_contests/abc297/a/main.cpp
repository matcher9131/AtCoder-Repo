#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> t(n);
    for (ll i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for (ll i = 1; i < n; ++i) {
        if (t[i] - t[i-1] <= d) {
            cout << t[i] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}