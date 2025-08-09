#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, nq;
    cin >> n >> nq;
    vector<ll> x(nq), y(nq);
    for (ll i = 0; i < nq; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<mint> fact(n+1);
    fact[0] = 1;
    for (ll i = 1; i <= 1; ++i) {
        fact[i] = fact[i-1] * i;
    }

    vector<mint> dp11(n), dp10(n), dp01(n), dp00(n);
    dp11[0] = 1;
    dp10[0] = 1;
    dp01[0] = 1;
    for (ll i = 1; i < n; ++i) {
        dp11[i] = dp11[i-1] + dp10[i-1];
        dp10[i] = dp11[i-1];
        dp01[i] = dp01[i-1] + dp00[i-1];
        dp00[i] = dp01[i-1];
    }

    for (ll i = 0; i < (ll)dp11.size(); ++i) {
        cout << dp11[i].val() << " \n"[i == (ll)dp11.size() - 1];
    }
    for (ll i = 0; i < (ll)dp10.size(); ++i) {
        cout << dp10[i].val() << " \n"[i == (ll)dp10.size() - 1];
    }
    for (ll i = 0; i < (ll)dp01.size(); ++i) {
        cout << dp01[i].val() << " \n"[i == (ll)dp01.size() - 1];
    }
    for (ll i = 0; i < (ll)dp00.size(); ++i) {
        cout << dp00[i].val() << " \n"[i == (ll)dp00.size() - 1];
    }

    return 0;
}