#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    ll zeroAns = 0;
    vector<ll> a, b;
    a.reserve(n);
    b.reserve(n);
    for (ll i = 0; i < n; ++i) {
        ll ai, bi;
        cin >> ai >> bi;
        if (ai == 0 && bi == 0) {
            ++zeroAns;
        } else {
            if (bi < 0) {
                ai *= -1;
                bi *= -1;
            }
            a.push_back(ai);
            b.push_back(bi);
        }
    }
    n = a.size();

    // A_i / B_i
    map<pair<ll, ll>, ll> m;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == 0) ++m[{0, 1}];
        else if (b[i] == 0) ++m[{1, 0}];
        else {
            ll g = gcd(a[i], b[i]);
            ++m[{a[i]/g, b[i]/g}];
        }
    }

    auto rev = [](const pair<ll, ll> &x) -> pair<ll, ll> {
        auto [a, b] = x;
        if (a == 0) return {1, 0};
        else if (b == 0) return {0, 1};
        else if (a < 0) return {b, -a};
        else return {-b, a};
    };

    mint ans = 1;
    set<pair<ll, ll>> used;
    for (const auto &[val, c] : m) {
        if (used.contains(val)) continue;
        auto other = rev(val);
        if (m.contains(other)) {
            ans *= mint(2).pow(c) + mint(2).pow(m[other]) - 1;
            used.insert(other);
        } else {
            ans *= mint(2).pow(c);
        }
    }
    ans -= 1;
    ans += zeroAns;

    cout << ans.val() << endl;

    return 0;
}