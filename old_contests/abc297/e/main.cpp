#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<ll> s{ 0 };
    ll ki = 0;
    auto it = s.begin();
    while (it != s.end()) {
        if (ki == k) {
            cout << *it << endl;
            return 0;
        }
        ll val = *it;
        for (ll i = 0; i < n; ++i) {
            s.insert(val + a[i]);
        }
        ++it;
        ++ki;
    }

    return 0;
}