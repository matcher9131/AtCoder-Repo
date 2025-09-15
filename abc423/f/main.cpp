#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

template<typename... Args>
pair<bool, ll> multiply(Args... args) {
    ll x = 1LL;
    bool overflows = false;
    for (const ll y : initializer_list<ll>{ args... }) {
        if (y == 0) return make_pair(false, 0);
        if (x > LLONG_MAX / y) {
            overflows = true;
        } else {
            x *= y;
        }
    }
    return overflows ? make_pair(true, 0LL) : make_pair(false, x);
}

int main() {
    ll n, m, y;
    cin >> n >> m >> y;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // LCMを求めてから発生回数に書き換える
    vector<ll> c(1 << n);
    c[0] = 1;
    for (ull bit = 0; bit < 1ULL<<n; ++bit) {
        for (ll i = 0; i < n; ++i) {
            if (bit & (1ULL << i)) continue;
            ll newBit = bit | (1LL << i);
            if (c[newBit] != 0) continue;
            if (c[bit] > y) c[newBit] = y+1;
            else {
                ll g = gcd(c[bit], a[i]);
                auto [overflows, result] = multiply(c[bit]/g, a[i]);
                c[newBit] = overflows ? y+1 : result;
            }
        }
    }
    for (ull bit = 0; bit < 1ULL<<n; ++bit) {
        c[bit] = y / c[bit];
        assert(c[bit] >= 0);
    }

    // メビウス変換
    // 各c[bit]は自身のsupersetとなるものの回数を含んでしまっているのでそれを引く
    for (ll i = 0; i < n; ++i) {
        for (ull bit = 0; bit < 1ULL<<n; ++bit) {
            if (bit & (1ULL << i)) continue;
            c[bit] -= c[bit | (1ULL << i)];
        }
    }
    
    ll ans = 0;
    for (ull bit = 0; bit < 1ULL<<n; ++bit) {
        if (popcount(bit) == m) ans += c[bit];
    }

    cout << ans << endl;
    return 0;
}