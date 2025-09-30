#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n);
    vector<ll> fu(n), fl(n);
    for (ll i = 0; i < n; ++i) {
        ll c;
        cin >> p[i] >> c;
        for (ll j = 0; j < c; ++j) {
            ll fij;
            cin >> fij;
            --fij;
            if (fij > 60) fu[i] |= 1LL << (fij - 60);
            else fl[i] |= 1LL << fij;
        }
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i == j) continue;
            if (p[i] >= p[j] && ((fu[j] & fu[i]) == fu[i]) && ((fl[j] & fl[i]) == fl[i]) && (p[i] > p[j] || fu[j] > fu[i] || fl[j] > fl[i])) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}