#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum ^= a[i];
    }

    if (sum > 0) {
        cout << -1 << endl;
    } else {
        sort(a.begin(), a.end(), greater<>());
        for (ll i = 0; i < n; ++i) {
            if (i == n-1 || a[i] != a[i+1]) {
                cout << a[i]-1 << endl;
                return 0;
            } else {
                ++i;
            }
        }
        cout << 0 << endl;
    }

    return 0;
}