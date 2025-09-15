#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    prev_permutation(a.begin(), a.end());

    for (ll i = 0; i < (ll)a.size(); ++i) {
        cout << a[i] << " \n"[i == (ll)a.size() - 1];
    }

    return 0;
}