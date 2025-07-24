#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

vector<ll> getDivisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n/i) res.push_back(n/i);
        }
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    auto isOK = [&](ll x, ll y) -> bool {
        for (ll i = 0; i < n; ++i) {
            bool ok = (a[i] % x == 0 && b[i] % y == 0) || (b[i] % x == 0 && a[i] % y == 0);
            if (!ok) return false;
        }
        return true;
    };

    vector<ll> da = getDivisors(a[0]), db = getDivisors(b[0]);
    ll ans = 0;
    for (const ll x : da) {
        for (const ll y : db) {
            if (isOK(x, y)) {
                ans = max(ans, x * y / gcd(x, y));
            }
        }
    }

    cout << ans << endl;
    return 0;
}