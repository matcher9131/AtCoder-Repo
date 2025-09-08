#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll x;
    cin >> x;
    
    // (2m+2n+1)(2m-2n-1) = 4x - 1
    ll y = 4*x-1;
    set<ll> ans;
    auto add = [&](ll p, ll q) -> void {
        // 2m + 2n + 1 = p, 2m - 2n - 1 = q
        // m = (p+q) / 4, n = (p-q-2) / 4
        if ((p+q) % 4) return;
        if ((p-q-2) % 4) return;
        ans.insert((p-q-2) / 4);
    };
    for (ll p = 1; p * p <= abs(y); ++p) {
        if (y % p) continue;
        ll q = y / p;
        add(p, q);
        add(q, p);
        add(-p, -q);
        add(-q, -p);
    }

    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        if (it != ans.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;

    return 0;
}