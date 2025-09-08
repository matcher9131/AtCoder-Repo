#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, nq;
    string s;
    cin >> n >> nq >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n-1; ++i) {
        if (s[i] == s[i+1]) a[i+1] = 1;
    }
    for (ll i = 0; i < n-1; ++i) {
        a[i+1] += a[i];
    }

    while (nq--) {
        ll l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << a[r] - a[l] << endl;
    }

    return 0;
}