#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;

    set<ll> ans;
    for (ll i = 0; i < k; ++i) {
        if (a+i <= b) ans.insert(a+i);
        if (b-i >= a) ans.insert(b-i);
    }

    for (const ll x : ans) {
        cout << x << endl;
    }

    return 0;
}