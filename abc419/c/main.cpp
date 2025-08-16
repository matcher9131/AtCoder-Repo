#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll tx = (x[n-1] - x[0] + 1) / 2;
    ll ty = (y[n-1] - y[0] + 1) / 2;
    cout << max(tx, ty) << endl;

    return 0;
}