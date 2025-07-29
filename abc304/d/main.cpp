#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll w, h, n;
    cin >> w >> h >> n;
    vector<ll> p(n), q(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i] >> q[i];
    }
    ll lenA;
    cin >> lenA;
    vector<ll> a(lenA);
    for (ll i = 0; i < lenA; ++i) {
        cin >> a[i];
    }
    ll lenB;
    cin >> lenB;
    vector<ll> b(lenB);
    for (ll i = 0; i < lenB; ++i) {
        cin >> b[i];
    }

    map<pair<ll, ll>, ll> m;
    for (ll i = 0; i < n; ++i) {
        ll x = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
        ll y = lower_bound(b.begin(), b.end(), q[i]) - b.begin();
        ++m[{x,y}];
    }

    ll ansMin = INF, ansMax = 0;
    for (const auto &[_, count] : m) {
        ansMin = min(ansMin, count);
        ansMax = max(ansMax, count);
    }
    if ((ll)m.size() < (lenA + 1) * (lenB + 1)) {
        ansMin = 0;
    }

    cout << ansMin << " " << ansMax << endl;
    return 0;
}