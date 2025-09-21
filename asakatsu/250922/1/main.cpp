#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    vector<ll> a(3);
    for (ll i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    ll b = a[1];
    sort(a.begin(), a.end());

    cout << (a[1] == b ? "Yes" : "No") << endl;

    return 0;
}