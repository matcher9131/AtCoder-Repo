#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, nq;
    cin >> n >> nq;
    string s;
    cin >> s;

    vector<ll> ans(n);
    for (ll i = 1; i < n; ++i) {
        ans[i] = ans[i-1] + (s[i-1] == s[i]);
    }

    while (nq--) {
        ll l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << (l > 0 ? ans[r] - ans[l] : ans[r]) << endl;
    }

    return 0;
}