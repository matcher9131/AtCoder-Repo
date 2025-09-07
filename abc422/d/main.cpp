#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(1LL << n);
    a[0] = k % (1LL << n);
    for (ll j = n; j > 0; --j) {
        for (ll i = 0; i < (1LL << n); i += (1LL << j)) {
            ll x = a[i] / 2 + a[i] % 2;
            ll y = a[i] / 2;
            a[i] = x;
            a[i + (1LL << (j-1))] = y;
        }
    }

    for (ll i = 0; i < (1LL << n); ++i) {
        a[i] += k / (1LL << n);
    }

    cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << endl;
    for (ll i = 0; i < (ll)a.size(); ++i) {
        cout << a[i] << " \n"[i == (ll)a.size() - 1];
    }

    return 0;
}